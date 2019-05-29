/*
** EPITECH PROJECT, 2018
** shell_launch.c
** File description:
** launch the shell to exec a command
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include "minishell_1.h"
#include "stdc.h"

/*
** To create a sigsegv fault without a dump core :
**	Use the function prctl with option PR_SET_DUMPABLE
*/
static void	handle_sigsegv_sigfpe(int status)
{
	if (WTERMSIG(status) == SIGSEGV) {
		my_putstr_err(strsignal(SIGSEGV));
		if (WCOREDUMP(status))
			my_putstr_err(" (core dumped)");
		my_putstr_err("\n");
	}
	if (WTERMSIG(status) == SIGFPE) {
		my_putstr_err("Floating exception");
		if (WCOREDUMP(status))
			my_putstr_err(" (core dumped)");
		my_putstr_err("\n");
	}
}

static int	wait_for_child(pid_t pid)
{
	int	status = 0;
	int	previous_return_value_of_child = 0;

	do {
		waitpid(pid, &status, WUNTRACED);
	} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	if (WIFSIGNALED(status)) {
		handle_sigsegv_sigfpe(status);
		previous_return_value_of_child = WTERMSIG(status) + 128;
	}
	if (WIFEXITED(status))
		previous_return_value_of_child = WEXITSTATUS(status);
	return (previous_return_value_of_child);
}

int	handle_child_new_process(char **argv, char **env, int *return_value)
{
	if (my_execvpe(argv[0], argv, env) == -1) {
		if (errno == ENOEXEC) {
			*return_value = 126;
			return (126);
		}
	}
	return (0);
}

/*
** We have to create/duplicate new process(fork) because execv
** replaces our process by a new command process
*/
int	shell_split_process(char **argv, char **env, uint8_t redirection)
{
	pid_t		pid;
	static int	child_return_value = 0;
	static int	fd_in[2];
	static int	fd_duo[2];
	static bool	fd_duo_exist = false;

	if (!(redirection & PIPE_OUT))
		fd_duo_exist = false;
	handle_command_echo_dollar(argv, child_return_value);
	if (check_user_permissions(argv[0], argv, env))
		return (KEEP_LOOPING);
	if ((redirection & (PIPE_OUT | PIPE_IN)) == (PIPE_OUT | PIPE_IN)) {
		fd_duo_exist = true;
		if (pipe(fd_duo)) {
			perror("Pipe out failed\n");
			return (ERROR_EXIT);
		    }
	}
	else if (redirection & PIPE_IN) {
		if (pipe(fd_in)) {
			perror("Pipe in failed\n");
			return (ERROR_EXIT);
		}
	}
	pid = fork();
	if (pid == -1) {
		perror("Fork Failed\n");
		return (ERROR_EXIT);
	}
	if (pid == 0) {
		if ((redirection & (PIPE_OUT | PIPE_IN)) == (PIPE_OUT | PIPE_IN)) {
			dup2(fd_duo[1], STDOUT_FILENO);
			dup2(fd_in[0], STDIN_FILENO);
			close(fd_in[1]);
			close(fd_duo[0]);
		} else {
			if (redirection & PIPE_IN) {
				dup2(fd_in[1], STDOUT_FILENO);
				close(fd_in[0]);
			}
			if (redirection & PIPE_OUT) {
				if (fd_duo_exist) {
					dup2(fd_duo[0], STDIN_FILENO);
					close(fd_duo[1]);
					close(fd_in[0]);
					close(fd_in[1]);
				} else {
					dup2(fd_in[0], STDIN_FILENO);
					close(fd_in[1]);
				}
			}
		}
		if (handle_child_new_process(argv, env, &child_return_value))
			return (126);
	} else {
		if (redirection & PIPE_OUT) {
			if (fd_duo_exist) {
			//	close(fd_duo[1]);
			//	close(fd_duo[0]);
				close(fd_in[0]);
			//	close(fd_in[1]);
			} else {
				child_return_value = wait_for_child(pid);
			}
		}
	}
	if ((redirection & (PIPE_OUT | PIPE_IN)) == (PIPE_OUT | PIPE_IN)) {
		//close(fd_duo[0]);
		//close(fd_in[0]);
	} else {
		if (redirection & PIPE_IN)
			close(fd_in[1]);
		if (redirection & PIPE_OUT) {
			if (fd_duo_exist) {
				close(fd_duo[0]);
			//	close(fd_in[0]);
			//	close(fd_in[1]);
			} else
				close(fd_in[0]);
		}
	}
	return (KEEP_LOOPING);
}

/*
** Argv[0] is the command
** Argv[1] is the first param of the command
** Argv[2] is the second param of the command ...
*/
int	shell_launch(all_builtins_commands_t	*tab_builtins,
			char			**argv,
			char			**env,
			uint8_t			redirection_detected)
{
	int	return_value = 0;

	for (int i = 0 ; i < BUILTINS_NB ; ++i)
		if (my_strcmp(argv[0], tab_builtins[i].command_name) == 0)
			return (tab_builtins[i].command_fct(argv, env));
	return_value = shell_split_process(argv, env, redirection_detected);
	return (return_value);
}

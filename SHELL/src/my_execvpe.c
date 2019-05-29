/*
** EPITECH PROJECT, 2018
** execvpe.c
** File description:
** man execvpe
*/

#include <unistd.h>
#include <errno.h>
#include "minishell_1.h"
#include "stdc.h"

static void	print_err_enoexec(char *command)
{
	if (errno == ENOEXEC) {
		my_putstr_err(command);
		my_putstr_err(": ");
		my_putstr_err(command);
		my_putstr_err(": cannot execute binary file\n");
	}
}

static int	handle_case_dot_slash(char **argv, char **envp)
{
	if (is_trying_to_exec_bin(argv[0])) {
		if (execve(argv[0], argv, envp) == -1) {
			print_err_enoexec(argv[0]);
			return (-1);
		}
		return (0);
	}
	return (1);
}

static int exec_from_path(char *file,
			char **paths,
			char **argv,
			char **envp)
{
	int i = 0;

	while (paths[i] != NULL) {
		paths[i] = my_strcat_alloc(paths[i], "/");
		paths[i] = my_strcat_alloc(paths[i], file);
		i++;
	}
	i = 0;
	while (paths[i] != NULL) {
		if (execve(paths[i], argv, envp) != -1) {
			free_two_dims_tab((void **)paths);
			return (0);
		}
		i++;
	}
	free_two_dims_tab((void **)paths);
	return (-1);
}

int	my_execvpe(char *file, char **argv, char **envp)
{
	char	**paths = NULL;
	int	return_value = 0;

	return_value = handle_case_dot_slash(argv, envp);
	if (return_value == 0)
		return (0);
	else if (return_value == -1)
		return (-1);
	paths = my_str_to_line_array(get_env_result(envp, "PATH"), ':', 1);
	return (exec_from_path(file, paths, argv, envp));
}

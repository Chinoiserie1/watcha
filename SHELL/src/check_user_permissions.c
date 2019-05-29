/*
** EPITECH PROJECT, 2018
** check_user_permission.c
** File description:
** Check user permission
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "minishell_1.h"
#include "stdc.h"

static int	handle_case_dot_slash(char *command_name)
{
	struct stat	info;

	if (is_trying_to_exec_bin(command_name)) {
		if (access(command_name, F_OK) == -1) {
			my_putstr_err(command_name);
			my_putstr_err(": Command not found.\n");
			return (-1);
		}
		stat(command_name, &info);
		if (access(command_name, X_OK) == -1 || S_ISDIR(info.st_mode)) {
			my_putstr_err(command_name);
			my_putstr_err(": Permission denied.\n");
			return (-1);
		}
		return (0);
	}
	return (1);
}

static bool	find_one_executable_file(char **paths, int i)
{
	if (access(paths[i], F_OK) != -1) {
		if (access(paths[i], X_OK) == -1)
			perror(paths[i]);
		else {
			free_two_dims_tab((void **)paths);
			return (0);
		}
	}
	return (1);
}

static bool	exec_from_path(char *file, char **paths)
{
	int i = 0;

	while (paths[i] != NULL) {
		paths[i] = my_strcat_alloc(paths[i], "/");
		paths[i] = my_strcat_alloc(paths[i], file);
		i++;
	}
	i = 0;
	while (paths[i] != NULL) {
		if (find_one_executable_file(paths, i) == 0)
			return (0);
		i++;
	}
	my_putstr_err(file);
	my_putstr_err(": Command not found.\n");
	free_two_dims_tab((void **)paths);
	return (1);
}

bool	check_user_permissions(char *file, char **argv, char **envp)
{
	char	**paths = NULL;
	int	return_value = 0;

	return_value = handle_case_dot_slash(argv[0]);
	if (return_value == 0)
		return (0);
	else if (return_value == -1)
		return (1);
	paths = my_str_to_line_array(get_env_result(envp, "PATH"), ':', 1);
	return (exec_from_path(file, paths));
}

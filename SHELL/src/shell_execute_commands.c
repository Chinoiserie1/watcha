/*
** EPITECH PROJECT, 2018
** shell_execute_commands.c
** File description:
** function that duplicate process, and exec commands
*/

#include <stdlib.h>
#include "minishell_1.h"
#include "stdc.h"

static int	change_env(	int	return_value,
				char	***env,
				char	**argv)
{
	int index = 0;

	if (return_value == ADD_ENV) {
		*env = add_env_variable(argv[1], argv[2], *env);
		return_value = KEEP_LOOPING;
	}
	else if (return_value == REMOVE_ENV) {
		index = get_index_two_dims_tab(*env, argv[1]);
		*env = remove_str_from_two_dims_tab(*env, index);
		return_value = KEEP_LOOPING;
	}
	return (return_value);
}

int	shell_execute(char **argv, char ***env, uint8_t redirection)
{
	int			return_value = 0;
	all_builtins_commands_t	*tab_builtins = NULL;

	if (argv[0] == NULL)
		return (KEEP_LOOPING);
	if (my_strcmp(argv[0], "exit") == 0) {
		my_printf("exit\n");
		cd_command(NULL, NULL);
		return (NORMAL_EXIT);
	}
	tab_builtins = malloc(sizeof(all_builtins_commands_t) * BUILTINS_NB);
	if (tab_builtins == NULL)
		return (ERROR_EXIT);
	tab_builtins = init_tab_builtins(tab_builtins);
	return_value = shell_launch(tab_builtins, argv, *env, redirection);
	return_value = change_env(return_value, env, argv);
	free(tab_builtins);
	return (return_value);
}

/*
** EPITECH PROJECT, 2018
** builtins.c
** File description:
** builtins shell
*/

#include <unistd.h>
#include <stdlib.h>
#include "stdc.h"
#include "minishell_1.h"

all_builtins_commands_t	*init_tab_builtins(all_builtins_commands_t *tab_builtin)
{
	tab_builtin[0].command_name = "cd";
	tab_builtin[0].command_fct = &cd_command;
	tab_builtin[1].command_name = "env";
	tab_builtin[1].command_fct = &env_command;
	tab_builtin[2].command_name = "setenv";
	tab_builtin[2].command_fct = &setenv_command;
	tab_builtin[3].command_name = "unsetenv";
	tab_builtin[3].command_fct = &unsetenv_command;
	return (tab_builtin);
}

int	env_command(char **argv, char **env)
{
	(void)argv;
	for (int i = 0 ; env[i] != NULL ; ++i)
		my_printf("%s\n", env[i]);
	return (KEEP_LOOPING);
}

static bool	handle_error_case_unsetenv(char **argv)
{
	if (argv[1] == NULL) {
		my_putstr_err(argv[0]);
		my_putstr_err(": Too few arguments.\n");
		return (1);
	}
	if (my_strcmp(argv[1], "PATH") == 0) {
		my_putstr_err(argv[0]);
		my_putstr_err(": Variable PATH cannot be removed.\n");
		return (1);
	}
	return (0);
}

int	unsetenv_command(char **argv, char **env)
{
	int	i = 0;
	char	*tmp = NULL;

	if (handle_error_case_unsetenv(argv))
		return (KEEP_LOOPING);
	tmp = cpy_env_variable(argv[1]);
	if (tmp == NULL)
		return (ERROR_EXIT);
	while (env[i] != NULL) {
		if (my_strncmp(env[i], tmp, my_strlen(tmp)) == 0) {
			free(tmp);
			return (REMOVE_ENV);
		}
		i++;
	}
	free(tmp);
	return (KEEP_LOOPING);
}

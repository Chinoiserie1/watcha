/*
** EPITECH PROJECT, 2018
** main_minishell_1.c
** File description:
** main minishell
*/

#include <stdlib.h>
#include "stdc.h"
#include "minishell_1.h"

static char	**create_backup_env(void)
{
	char **new_env = NULL;

	new_env = malloc(sizeof(char *) * 2);
	if (new_env == NULL)
		return (NULL);
	new_env[0] = my_strdup("PATH=/usr/local/bin:/usr/bin:/bin");
	if (new_env[0] == NULL)
		return (NULL);
	new_env[1] = NULL;
	return (new_env);
}

static char	**cpy_ev(char **src)
{
	char	**ev_cpy = NULL;

	if (src[0] == NULL)
		ev_cpy = create_backup_env();
	else
		ev_cpy = strdup_two_dims_str_tab(src);
	if (ev_cpy == NULL)
		my_putstr_err("Malloc issue\n");
	return (ev_cpy);
}

static bool	display_help(int argc, char **argv)
{
	if (argc == 2) {
		if (my_strcmp(argv[1], "-h") == 0) {
			my_printf("Sorry, this shell has no help page yet\n");
			return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv, char **ev)
{
	char	**ev_cpy = NULL;
	char	return_value = 0;

	if (display_help(argc, argv))
		return (0);
	ev_cpy = cpy_ev(ev);
	if (ev_cpy == NULL)
		return (EXIT_ERROR);
	return_value = shell_loop(&ev_cpy);
	if (return_value == NORMAL_EXIT) {
		free_two_dims_tab((void **)ev_cpy);
		return (0);
	}
	else if (return_value == ERROR_EXIT) {
		free_two_dims_tab((void **)ev_cpy);
		return (EXIT_ERROR);
	} else {
		free_two_dims_tab((void **)ev_cpy);
		return (return_value);
	}
}

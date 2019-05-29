/*
** EPITECH PROJECT, 2018
** cd_options.c
** File description:
** handle cd_options
*/

#include <stdlib.h>
#include <unistd.h>
#include "minishell_1.h"
#include "stdc.h"

void	display_cd_dest(char option, char **env)
{
	char	*tmp = NULL;
	char	*home_dir = NULL;
	char	*dest = getcwd(NULL, 0);

	if (option == 'p') {
		home_dir = get_env_result(env, "HOME");
		if (my_strncmp(dest, home_dir, my_strlen(home_dir)) == 0) {
			tmp = my_strcat_alloc(tmp, "~");
			tmp = my_strcat_alloc(tmp, dest + my_strlen(home_dir));
		}
		my_printf("%s \n", tmp);
		free(tmp);
	}
	if (option == 'l')
		my_printf("%s \n", dest);
	free(dest);
}

bool	is_cd_valid_arg(char *arg)
{
	return ((my_strcmp(arg, "-p") != 0
	&& my_strcmp(arg, "-l") != 0
	&& my_strcmp(arg, "-v") != 0
	&& my_strcmp(arg, "-n") != 0) ? 0 : 1);
}

char	get_option(bool opt_psi, bool opt_lambda, bool opt_velo, bool opt_nul)
{
	char	final = 0;

	if (opt_psi || opt_velo || opt_nul)
		final = 'p';
	if (opt_lambda)
		final = 'l';
	return (final);
}

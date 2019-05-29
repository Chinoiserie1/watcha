/*
** EPITECH PROJECT, 2018
** setenv.c
** File description:
** man setenv
*/

#include <stdlib.h>
#include "stdc.h"
#include "minishell_1.h"

static bool	set_env_line(char **env, int i, char *tmp, char **argv)
{
	char	*line_env = NULL;

	if (my_strncmp(env[i], tmp, my_strlen(tmp)) == 0) {
		line_env = my_strcat_alloc(line_env, argv[1]);
		line_env = my_strcat_alloc(line_env, "=");
		if (argv[2] != NULL)
			line_env = my_strcat_alloc(line_env, argv[2]);
		env[i] = line_env;
		return (1);
	}
	return (0);
}

char	**add_env_variable(char *variable, char *value, char **env)
{
	int	size_env = get_size_two_dims_tab((void **)env);
	char	*line = my_strdup(variable);

	if (line == NULL)
		return (NULL);
	line = my_strcat_alloc(line, "=");
	env = realloc_two_dims_str_tab(env, sizeof(char *) * (size_env + 2));
	if (line == NULL || env == NULL)
		return (NULL);
	if (value != NULL)
		line = my_strcat_alloc(line, value);
	if (line == NULL)
		return (NULL);
	env[size_env] = line;
	env[size_env + 1] = NULL;
	return (env);
}

char	*cpy_env_variable(char *variable)
{
	char	*tmp = NULL;

	tmp = my_strcat_alloc(tmp, variable);
	if (tmp == NULL)
		return (NULL);
	tmp = my_strcat_alloc(tmp, "=");
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}

bool	handle_error_case_setenv(int argc, char **argv)
{
	if (argc > 3) {
		my_putstr_err("setenv: Too many arguments.\n");
		return (1);
	}
	if (!is_letter(argv[1][0])) {
		my_putstr_err(argv[0]);
		my_putstr_err(": Variable name must begin with a letter.\n");
		return (1);
	}
	if (!my_str_is_alphanumeric(argv[1])) {
		my_putstr_err(argv[0]);
		my_putstr_err(": Variable name must contain \
alphanumeric characters.\n");
		return (1);
	}
	return (0);
}

int	setenv_command(char **argv, char **env)
{
	int	i = 0;
	char	*tmp = NULL;
	int	argc = get_size_two_dims_tab((void **)argv);

	if (argc == 1)
		return (env_command(argv, env));
	if (handle_error_case_setenv(argc, argv))
		return (KEEP_LOOPING);
	tmp = cpy_env_variable(argv[1]);
	while (env[i] != NULL) {
		if (set_env_line(env, i, tmp, argv)) {
			free(tmp);
			return (KEEP_LOOPING);
		}
		i++;
	}
	free(tmp);
	return (ADD_ENV);
}

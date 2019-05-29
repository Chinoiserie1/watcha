/*
** EPITECH PROJECT, 2018
** transform_dollar_variables.c
** File description:
** transform_dollar_variables into equivalent env variable
*/

#include <stdlib.h>
#include "stdc.h"
#include "minishell_1.h"

static char	*get_variable_name(char *line)
{
	char	*variable_name = NULL;
	int	i = 0;

	while (!is_space(line[i]) && line[i] != '\0')
		i++;
	if (line[i] != '\0')
		i--;
	variable_name = truncate_str(line, 1, i);
	return (variable_name);
}

static char	*replace_new_line(char *line, int i, char *tmp)
{
	while (!is_space(line[i]) && line[i] != '\0') {
		line = remove_char_from_str(line, i);
		if (line == NULL)
			return (NULL);
	}
	line = add_str_inside_str(line, tmp, i);
	if (line == NULL)
		return (NULL);
	return (line);
}

static char	*do_the_transform(char *line, int *i2, char **env)
{
	char	*variable_name = NULL;
	char	*tmp = NULL;
	int	i = *i2;

	if (line[i] == '$' && line[i + 1] != '\0' && line[i + 1] != '?') {
		variable_name = get_variable_name(line + i);
		tmp = get_env_result(env, variable_name);
		if (tmp == NULL) {
			my_putstr_err(variable_name);
			my_putstr_err(": Undefined variable.\n");
			free(line);
			free(variable_name);
			return (my_strdup(""));
		}
		line = replace_new_line(line, i, tmp);
		free(variable_name);
		*i2 = 0;
	}
	return (line);
}

char	*transform_dollar_variables(char *line, char **env)
{
	int	i = 0;

	while (line[i + 1] != '\0') {
		line = do_the_transform(line, &i, env);
		if (line == NULL)
			return (NULL);
		if (my_strcmp(line, "") == 0)
			break;
		i++;
	}
	return (line);
}

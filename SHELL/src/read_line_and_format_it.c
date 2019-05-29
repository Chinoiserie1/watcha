/*
** EPITECH PROJECT, 2018
** read_line_and_format_it.c
** File description:
** read_line_and_format_it
*/

#include <stdlib.h>
#include <signal.h>
#include "minishell_1.h"
#include "stdc.h"

static char	*shell_read_line(void)
{
	char	*line = NULL;

	line = get_next_line(0);
	if (line == NULL) {
		line = my_strdup("exit\n");
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

static int	move_index_to_next_quote(char *line, int i)
{
	if (line[i] == '"') {
		do
			i++;
		while (line[i] != '\0' && line[i] != '"');
	}
	return (i);
}

static int	move_index_to_next_space(char *line, int i)
{
	while (!is_space(line[i]) && line[i] != '\0') {
		i = move_index_to_next_quote(line, i);
		if (line[i] == '\0')
			break;
		i++;
	}
	return (i);
}

char	*line_formatting(char *line)
{
	int	i = 0;

	while (is_space(line[0])) {
		line = remove_char_from_str(line, 0);
		if (line == NULL)
			return (NULL);
	}
	while (line[i] != '\0') {
		i = move_index_to_next_space(line, i);
		while (is_space(line[i]))
			line = remove_char_from_str(line, i);
		line = add_char_to_str(line, ' ', i);
		if (line == NULL)
			return (NULL);
		i++;
	}
	if (i != 0)
		line = remove_char_from_str(line, i - 1);
	return (line);
}

char	*read_line_and_format_it(char **env)
{
	char	*line = NULL;

	signal(SIGINT, &sig_handler_before_command);
	line = shell_read_line();
	if (line == NULL)
		return (NULL);
	line = line_formatting(line);
	signal(SIGINT, &sig_handler_after_command);
	line = transform_tildes(line);
	line = transform_dollar_variables(line, env);
	return (line);
}

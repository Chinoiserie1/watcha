/*
** EPITECH PROJECT, 2018
** echo_dollar_question_mark.c
** File description:
** handle_a_special_case_echo_dollar_question_mark
*/

#include <stdlib.h>
#include "minishell_1.h"
#include "stdc.h"

static char	*transform_dollar_question_mark(char *line_with_dollar,
						int child_return_value)
{
	if (my_strcmp(line_with_dollar, "$?") == 0) {
		free(line_with_dollar);
		line_with_dollar = my_itoa(child_return_value);
	}
	return (line_with_dollar);
}

void	handle_command_echo_dollar(char **argv, int child_return_value)
{
	int i = 1;

	if (my_strcmp(argv[0], "echo") == 0) {
		while (argv[i] != NULL) {
			argv[i] = transform_dollar_question_mark(argv[i],
							child_return_value);
			i++;
		}
	}
}

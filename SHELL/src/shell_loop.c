/*
** EPITECH PROJECT, 2018
** shell_loop.c
** File description:
** main function of the shell
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "stdc.h"
#include "minishell_1.h"

char	*get_env_result(char **env, char *selection)
{
	for (int i = 0 ; env[i] != NULL ; ++i)
		if (my_strncmp(env[i], selection, my_strlen(selection)) == 0)
			return (env[i] + my_strlen(selection) + 1);
	return (NULL);
}

bool	display_prompt_and_before(void)
{
	char	*pwd_command_result = getcwd(NULL, 0);

	if (pwd_command_result == NULL) {
		my_putstr_err("getcwd error\n");
		return (1);
	}
	pwd_command_result = add_char_to_str(pwd_command_result, '[', 0);
	pwd_command_result = my_strcat_alloc(pwd_command_result, "]");
	pwd_command_result = my_strcat_alloc(pwd_command_result, " $>");
	my_printf(pwd_command_result);
	free(pwd_command_result);
	return (0);
}

int	move_forward_to_next_quote(char *str, int i)
{
	while (str[i] != '\0' && str[i] != '"')
		++i;
	return (i);
}

uint8_t *fill_redirection_tab(char *line, uint8_t *tab)
{
	int i2 = 0;

	for (int i = 0 ; i < 1000 ; ++i)
		tab[i] = 0x0;
	for (int i = 0 ; line[i] != '\0' ; ++i) {
		if (line[i] == '"')
			i = move_forward_to_next_quote(line, i);
		if (line[i] == '|' || line[i] == ';') {
			tab[i2] |= (line[i] == '|') ? PIPE_IN : 0x0;
			tab[i2 + 1] |= (tab[i2] & PIPE_IN) ? PIPE_OUT : 0x0;
			++i2;
		}
	}
	return (tab);
}

int	handle_command_line(char *line, char ***ev)
{
	char	**argv = NULL;
	char	**commands = NULL;
	int	exit_status = KEEP_LOOPING;
	uint8_t *tab_redirection = malloc(1000);

	if (tab_redirection == NULL)
		return (ERROR_EXIT);
	tab_redirection = fill_redirection_tab(line, tab_redirection);
	commands = my_str_cut_word_double_quote(line, ";|", 1);
	if (commands == NULL)
		return (ERROR_EXIT);
	for (int i = 0 ;
	commands[i] != NULL && exit_status == KEEP_LOOPING ; ++i) {
		commands[i] = line_formatting(commands[i]);
		argv = my_str_cut_word_double_quote(commands[i], " ", 1);
		if (argv == NULL)
			return (ERROR_EXIT);
		exit_status = shell_execute(argv, ev, tab_redirection[i]);
		free_two_dims_tab((void **)argv);
	}
	free_two_dims_tab((void **)commands);
	return (exit_status);
}

int	shell_loop(char ***ev)
{
	char	*line = NULL;
	int	exit_status = KEEP_LOOPING;
	char	*prompt = NULL;

	do {
		if (display_prompt_and_before())
			return (ERROR_EXIT);
		line = read_line_and_format_it(*ev);
		if (line == NULL)
			return (ERROR_EXIT);
		exit_status = handle_command_line(line, ev);
		free(line);
	} while (exit_status == KEEP_LOOPING);
	free(prompt);
	return (exit_status);
}

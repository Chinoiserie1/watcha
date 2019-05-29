/*
** EPITECH PROJECT, 2018
** tilde.c
** File description:
** handle tildes
*/

#include "stdc.h"

char	*transform_tildes(char *line)
{
	int	i = 0;

	while (line[i] != '\0') {
		if (line[i] == '~') {
			line = remove_char_from_str(line, i);
			line = add_str_inside_str(line, "$HOME", i);
			i = 0;
		}
		i++;
	}
	return (line);
}

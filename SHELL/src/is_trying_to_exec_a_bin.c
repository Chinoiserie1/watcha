/*
** EPITECH PROJECT, 2018
** is_trying_to_exec_bin.c
** File description:
** is_trying_to_exec_a_bin
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stdc.h"

bool	is_a_dir(char *path)
{
	struct stat	info;

	if (stat(path, &info) == -1)
		return (false);
	if (S_ISDIR(info.st_mode))
		return (true);
	return (false);
}

bool	is_trying_to_exec_bin(char *command)
{
	char	*before_slash = NULL;

	for (int i = 0 ; command[i] != '\0' && command[i] != '/' ; ++i) {
		before_slash = truncate_str(command, 0, i);
		if (my_strcmp(before_slash, ".") == 0
		|| my_strcmp(before_slash, "..") == 0
		|| is_a_dir(before_slash)) {
			free(before_slash);
			return (true);
		}
	}
	free(before_slash);
	return (false);
}

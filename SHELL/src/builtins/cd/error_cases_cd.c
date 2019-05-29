/*
** EPITECH PROJECT, 2018
** error_cases_cd.c
** File description:
** error cases_cd
*/

#include <errno.h>
#include "stdc.h"

void	handle_chdir_error_cases(char *dir)
{
	if (errno == ENOTDIR) {
		my_putstr_err(dir);
		my_putstr_err(": Not a directory.\n");
	} else
		perror(dir);
}

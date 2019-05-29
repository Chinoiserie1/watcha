/*
** EPITECH PROJECT, 2018
** my_putstr_err.c
** File description:
** put a message in the stderr
*/

#include <unistd.h>

void	my_putchar_err(char c)
{
	write(2, &c, 1);
}

void	my_putstr_err(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar_err(str[i]);
		i++;
	}
}

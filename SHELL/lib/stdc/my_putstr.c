/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** Display a str
*/

#include "stdc.h"

int	my_putstr(char const *str)
{
	unsigned int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}

int	my_putnstr(char *str, unsigned int n)
{
	unsigned int i = 0;

	while (str[i] != '\0' && i < n) {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}

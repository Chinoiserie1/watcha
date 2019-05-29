/*
** EPITECH PROJECT, 2018
** get_size_two_dims_tab.c
** File description:
** get_size of a two dim table
*/

#include <stdlib.h>

/*
** Table MUST be NULL terminated !
** Example : "First" "Second" "NULL". Function get_size_two_dims_tab returns 2.
*/
int	get_size_two_dims_tab(void **tab)
{
	int i = 0;

	while (tab[i] != NULL)
		i++;
	return (i);
}

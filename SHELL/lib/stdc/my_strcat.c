/*
** EPITECH PROJECT, 2018
** my_strcat.c
** File description:
** concatenates two strings
*/

#include "stdc.h"

char	*my_strcat(char *dest, char const *src)
{
	int i = 0;
	int i2 = 0;

	i = my_strlen(dest);
	while (src[i2] != '\0') {
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*my_strcat_alloc(char *dest, char const *src)
{
	int	nb_char_dest = 0;

	if (dest != NULL)
		nb_char_dest = my_strlen(dest);
	dest = my_realloc_str(dest, nb_char_dest + my_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	dest = my_strcat(dest, src);
	return (dest);
}

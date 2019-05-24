/*
** EPITECH PROJECT, 2018
** CPool_Day06_2018
** File description:
** strcpy
*/

#include "../include/include.h"

char *my_strcpy(char const *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * my_strlen(src) + 1);

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
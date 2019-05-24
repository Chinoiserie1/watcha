/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** my_strcat
*/

#include "../include/include.h"

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;
    int lenght = my_strlen(dest);
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * len + lenght + 1);

    while (dest[j] != '\0') {
        str[j] = dest[j];
        j++;
    }
    while (src[i] != '\0') {
        str[lenght + i] = src[i];
        i++;
    }
    str[lenght + i] = '\0';
    return (str);
}
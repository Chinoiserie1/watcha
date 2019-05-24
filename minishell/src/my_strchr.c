/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** my_strchr.c
*/

#include "../include/include.h"

int my_strchr(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
        return (0);
    }
    return (1);
}
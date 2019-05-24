/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** error_parser.c
*/

#include "../include/include.h"

int error_parser(char *str, char chara)
{
    if (str == NULL)
        return (1);
    if (chara == '\0')
        return (1);
    return (0);
}

char **error_parserbis(char *str, char c)
{
    char **tab = malloc(sizeof(char*) * 2);

    if (my_strchr(str, c) == 1) {
        tab[0] = str;
        tab[1] = NULL;
        return (tab);
    }
    return (NULL);
}
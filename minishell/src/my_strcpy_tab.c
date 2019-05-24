/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** my_strcpy_tab.c
*/

#include "../include/include.h"

char **my_strcpy_tab(char **tab)
{
    int i = 0;
    int j = 0;
    int nb_l = 0;
    char **res;

    while (tab[nb_l] != NULL)
        nb_l++;
    res = malloc(sizeof(char*) * nb_l + 1);
    while (tab[i] != NULL) {
        res[i] = malloc(sizeof(char) * my_strlen(tab[i]) + 1);
        res[i] = my_strcpy(tab[i]);
        i++;
    }
    res[i] = NULL;
    return res;
}
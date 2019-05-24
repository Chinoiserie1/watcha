/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** main fonction
*/

#include "../include/include.h"

int my_tablen(char **tab)
{
    int res = 0;
    int i = 0;
    int j = 0;

    while (tab[i] != NULL) {
        while (tab[i][j] != '\0') {
            res++;
            j++;
        }
        j = 0;
        i++;
    }
    return (res);
}

char *tab_to_str(char **tab)
{
    int nb_c = my_tablen(tab);
    char *str = malloc(sizeof(char) * nb_c + 1);
    int i = 0;
    int j = 0;
    int k = 0;

    while (tab[i] != NULL) {
        while (tab[i][j] != '\0') {
            str[k] = tab[i][j];
            k++;
            j++;
        }
        j = 0;
        i++;
    }
    str[k] = '\0';
    return (str);
}
/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** display environnement
*/

#include "../include/include.h"

void display_env(shell_t *sh)
{
    int i = 0;

    while (sh->envp[i] != NULL) {
        my_putstr(sh->envp[i]);
        my_putchar('\n');
        i = i + 1;
    }
}
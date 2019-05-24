/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** main fonction
*/

#include "../include/include.h"

char **my_unsetenv(shell_t *sh, char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int nb_l = nb_line(sh->envp);
    char **tab = malloc(sizeof(char*) * nb_l + 2);

    if (str == NULL)
        return (sh->envp);
    while (sh->envp[i] != NULL) {
        if (my_strncmp(sh->envp[i], str, my_strlen(str)) == 1) {
            i++;
            if (i == nb_l) {
                tab[j] = NULL;
                return (tab);
            }
        }
        tab[j] = malloc(sizeof(char) * my_strlen(sh->envp[i]));
        while (sh->envp[i][k] != '\0') {
            tab[j][k] = sh->envp[i][k];
            k++;
        }
        tab[j][k] = '\0';
        k = 0;
        i++;
        j++;
    }
    tab[j] = NULL;
    return (tab);
}
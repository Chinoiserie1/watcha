/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** main fonction
*/

#include "../include/include.h"

int nb_line(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i);
}

char *change_str(char *str)
{
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(char) * my_strlen(str) + 1);

    while (str[i] != '\0') {
        if (str[i] == ' ')
            i++;
        res[j] = str[i];
        j++;
        i++;
    }
    res[j] = '\0';
    return (res);
}

char **my_setenvbis(shell_t *sh, char *name, char *str)
{
    int k = 0;
    int j = 0;
    int nb_l = nb_line(sh->envp);
    char *s1 = change_str(str);
    char **tab = malloc(sizeof(char*) * nb_l + 2);

    while (sh->envp[j] != NULL) {
        tab[j] = malloc(sizeof(char) * my_strlen(sh->envp[j]));
        tab[j] = my_strcpy(sh->envp[j]);
        j++;
    }
    tab[j] = my_strcat(name, "=");
    tab[j] = my_strcat(tab[j], s1);
    tab[j + 1] = NULL;
    return (tab);
}

char **my_setenv3(shell_t *sh, char *name)
{
    int k = 0;
    int j = 0;
    int nb_l = nb_line(sh->envp);
    char **tab = malloc(sizeof(char*) * nb_l + 2);

    while (sh->envp[j] != NULL) {
        tab[j] = malloc(sizeof(char) * my_strlen(sh->envp[j]));
        tab[j] = my_strcpy(sh->envp[j]);
        j++;
    }
    tab[j] = malloc(sizeof(char) * (my_strlen(name) + 2));
    tab[j] = my_strcat(tab[j], name);
    tab[j] = my_strcat(tab[j], "=");
    tab[j + 1] = NULL;
    return (tab);
}

char **my_setenv(shell_t *sh, char *name, char *str)
{
    if (name != NULL || str != NULL) {
        for (int i = 0; sh->envp[i] != NULL; i++) {
            if (my_strncmp(sh->envp[i], name, my_strlen(name)) == 1) {
                sh->envp[i] = my_strcat(name, "=");
                sh->envp[i] = my_strcat(sh->envp[i], str);
                return (sh->envp);
            }
        }
    }
    if (name != NULL && str == NULL) {
        sh->envp =  my_setenv3(sh, name);
        return (sh->envp);
    }
    sh->envp = my_setenvbis(sh, name, str);
    return (sh->envp);
}
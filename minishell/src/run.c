/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** main fonction
*/

#include "../include/include.h"

shell_t *run_cmd2(shell_t *sh, char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        if (my_strncmp(tab[i], "setenv", 6) == 1) {
            sh->envp = my_setenv(sh, tab[i + 1], tab[i + 2]);
            sh->ps = 1;
        }
        if (my_strncmp(tab[i], "exit", 5) == 1)
            exit(0);
        if (my_strncmp(tab[i], "unsetenv", 8) == 1) {
            sh->envp = my_unsetenv(sh, tab[i + 1]);
            sh->ps = 1;
        }
        if (tab[i][0] == '\0')
            sh->ps = 1;
        i++;
    }
    return sh;
}

shell_t *run_cmd(shell_t *sh, char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        if (my_strncmp(tab[i], "cd", 2) == 1) {
            sh->envp = my_cd(sh, &i, tab);
            sh->ps = 1;
            return (sh);
        }
        if (my_strncmp(tab[i], "env", 3) == 1) {
                display_env(sh);
                sh->ps = 1;
        }
        if (my_strncmp(tab[i], "path", 4) == 1) {
            my_putstr(sh->path);
            my_putchar('\n');
        }
        i++;
    }
    return sh;
}

char **run(shell_t *sh)
{
    int l = 0;
    list_t *list = get_cmd(sh);
    list_t *j = list->next;

    if (list == NULL)
        return NULL;
    while (j != list) {
        sh = run_cmd(sh, j->cmd2);
        if (sh->ps != 1)
            sh = run_cmd2(sh, j->cmd2);
        j = j->next;
    }
    if (sh->ps != 1) {
        sh = run_f(sh, list);
    }
    return (sh->envp);
}
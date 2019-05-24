/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** run2.c
*/

#include "../include/include.h"

shell_t *run_exec(shell_t *sh, char **tab)
{
    exec_cmd(sh, tab, sh->envp);
    return (sh);
}

shell_t *run_f(shell_t *sh, list_t *list)
{
    list_t *i = list->next;
    get_path(sh);
    while (i != list) {
        sh = run_exec(sh, i->cmd2);
        i = i->next;
    }
    return sh;
}
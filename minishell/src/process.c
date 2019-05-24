/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** main fonction
*/

#include "../include/include.h"

void process(shell_t *sh)
{
    while (1) {
        get_pid(sh);
        sh->envp = run(sh);
        if (sh->stop == 1) {
            exit(0);
        }
    }
}
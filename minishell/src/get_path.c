/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** main fonction
*/

#include "../include/include.h"

void get_path(shell_t *sh)
{
    sh->path = get_env(sh->envp, "PATH=");
}
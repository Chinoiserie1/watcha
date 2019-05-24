/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** main fonction
*/

#include "../include/include.h"

void get_pid(shell_t *sh)
{
    sh->pid = getpid();
}
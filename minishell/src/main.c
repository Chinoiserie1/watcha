/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** main fonction
*/

#include "../include/include.h"

int main(int ac, char **av, char **env)
{
    shell_t sh;

    sh.envp = my_strcpy_tab(env);
    process(&sh);
    return (0);
}
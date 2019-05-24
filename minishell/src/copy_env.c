/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** copy_env.c
*/

#include "../include/include.h"

char **copy_env(char **env)
{
    int i = 0;
    char **res = malloc(sizeof(char) * nb_line(env) + 1);

    while (env[i] != NULL) {
        res[i] = malloc(sizeof(char) * my_strlen(env[i]) + 1);
        res[i] = my_strcpy(env[i]);
        i++;
    }
    res[i] = NULL;
    return (res);
}
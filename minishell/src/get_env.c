/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** main fonction
*/

#include "../include/include.h"

char *cut_str(char *dest, char *strc)
{
    char *res = malloc(sizeof(char) * (my_strlen(dest) - my_strlen(strc) + 1));
    int i = my_strlen(strc);
    int j = 0;

    while (dest[i] != '\0') {
        res[j] = dest[i];
        j++;
        i++;
    }
    return (res);
}

char *get_env(char **env, char *str)
{
    int i = 0;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], str, my_strlen(str)) == 1) {
            return (cut_str(env[i], str));
        }
        i++;
    }
    return (NULL);
}
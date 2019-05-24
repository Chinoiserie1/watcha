/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** parseur fonction
*/

#include "../include/include.h"

int my_strlen_for_parser(char *str, char chara, int i)
{
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] == chara)
            return (j);
        j++;
        i++;
    }
    return (j);
}
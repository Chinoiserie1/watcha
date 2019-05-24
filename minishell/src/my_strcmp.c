/*
** EPITECH PROJECT, 2018
** CPool_Day03_2018
** File description:
** strcmp
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    return (1);
}
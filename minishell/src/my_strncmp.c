/*
** EPITECH PROJECT, 2018
** CPool_Day03_2018
** File description:
** strncmp
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n) {
        if (s1[i] != s2[i]) {
            return (0);
        }
        i++;
    }
    return (1);
}
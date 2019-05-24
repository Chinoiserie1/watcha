/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** print str 
*/

#include "../include/include.h"

void my_putstr(char const *str)
{
    int a;

    for(a = 0; str[a] != '\0'; a++)
        my_putchar(str[a]);
}

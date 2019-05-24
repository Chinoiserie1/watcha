/*
** EPITECH PROJECT, 2018
** CPool_Day10_2018
** File description:
** print list
*/

#include "../include/include.h"

void print_list(list_t *first)
{
    list_t *i = first->next;

    while (i != first) {
        for (int j = 0; i->cmd2[j] != NULL; j++) {
            my_putstr(i->cmd2[j]);
            my_putchar('\n');
        }
        i = i->next;
    }
}

void print_list_rev(list_t *first)
{
    list_t *i = first->before;

    while (i != first) {
        my_putstr(i->str);
        i = i->before;
    }
}
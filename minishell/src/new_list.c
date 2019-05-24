/*
** EPITECH PROJECT, 2018
** CPool_Day10_2018
** File description:
** do_op
*/

#include "../include/include.h"

list_t *new_list(void)
{
    list_t *first = malloc(sizeof(list_t));

    if (first != NULL) {
        first->next = first;
        first->before = first;
    }
    return (first);
}
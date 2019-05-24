/*
** EPITECH PROJECT, 2018
** CPool_Day10_2018
** File description:
** new element next
*/

#include "../include/include.h"

char *str_del(char *str)
{
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(char) * my_strlen(str) + 1);

    while (str[i] != '\0') {
        if (str[i] == ' ' && i == 0)
            i++;
        while (str[i] == '\t')
            i++;
        while (str[i] == ' ' && str[i + 1] == ' ')
            i++;
        if (str[i] == ' ' && str[i + 1] == '\0')
            i++;
        if (str[i] == ' ' && str[i + 1] == ';')
            i++;
        if (str[i] == ' '& str[i - 1] == ';')
            i++;
        if (str[i] == '\n')
            i++;
        res[j] = str[i];
        i++;
        j++;
    }
    res[j] = '\0';
    return (res);
}

void add_element_after(list_t *element, char *str)
{
    list_t *new_element = malloc(sizeof(list_t));

    if (new_element != NULL) {
        new_element->str = str_del(str);
        new_element->cmd2 = my_parser(new_element->str, ' ');
        new_element->before = element;
        new_element->next = element->next;
        element->next->before = new_element;
        element->next = new_element;
    }
}
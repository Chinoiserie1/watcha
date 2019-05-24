/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** main fonction
*/

#include "../include/include.h"

int error_cmd(shell_t *sh, char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ' && i == 0 && str[i + 1] == '\0') {
            return (1);
        }
    }
    return (0);
}

list_t *get_cmd(shell_t *sh)
{
    int i = 0;
    list_t *list = new_list();
    list_t *first = list;
    size_t size = 0;
    char *buffer = NULL;

    sh->ps = 0;
    my_putstr("$> ");
    if (getline(&buffer, &size, stdin) == -1) {
        sh->stop = 1;
        exit(0);
    }
    if (size == 2)
        sh->ps = 1;
    sh->comd = my_parser(buffer, ';');
    while (sh->comd[i] != NULL) {
        add_element_after(list, sh->comd[i]);
        list = list->next;
        i++;
    }
    return (first);
}
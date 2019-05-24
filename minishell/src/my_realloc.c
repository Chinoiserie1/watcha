/*
** EPITECH PROJECT, 2018
** MY_REALLOC_2018
** File description:
** my realloc
*/

#include "../include/include.h"

// char *my_realloc(char *str, int size)
// {
//     char *realoc = malloc(sizeof(char) * (size + 1));
//     int i = 0;

//     if (str == NULL || size < 1)
//         return (NULL);
//     if (realoc == NULL)
//         return (NULL);
//     for( ; i != size && str[i] != '\0'; i++)
//         realoc[i] = str[i];
//  //     if (ptr[i] == '\0') {
//  //     while (i < size)
//  //         realoc[i++] = '\0';
//     // }
//     realoc[i] = '\0';
//     free(str);
//     return (realoc);
// }

// int main(int argc, char const *argv[])
// {
//     char *s1 = malloc(sizeof(char) * 5);
//     s1 = "zizi";
//     char *s2 = "cacaboudin";

//     s1 = s2;
//     printf("%s\n", s1);
//     return 0;
// }
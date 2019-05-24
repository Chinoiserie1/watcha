/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** parseur fonction
*/

#include "../include/include.h"

int str_nb_chara(char *str, char chara)
{
    int i = 0;
    int j = 1;

    while (str[i] != '\0') {
        if (str[i] == chara)
            j++;
        i++;
    }
    return (j);
}

char *str_delete2(char *str)
{
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(char) * my_strlen(str) + 1);

    while (str[i] != '\0') {
        if (str[i] == ' ' && str[i + 1] == ' ') {
            i++;
        }
        else 
            res[j] = str[i];
        j++;
        i++;
    }
    res[j] = '\0';
    return res;
}

char *str_delete(char *str, char chara)
{
    int i = 0;
    int j = 0;
    char *res = malloc(sizeof(char) * my_strlen(str) + 1);

    if (str[0] == ' ' && str[1] != ' ')
        i++;
    while (str[i] != '\0') {
        if (str[i] == ' ' && str[i + 1] == ';')
            i++;
        if (str[i] == ' ' && str[i + 1] == ' ') {
            i++;
        }
        if (str[i] == ' ' && str[i + 1] == '\0')
            res[j] = '\0';
        res[j] = str[i];
        i++;
        j++;
    }
    res[j] = '\0';
    return (res);
}

parser_t my_parser_bis(parser_t parser, char chara)
{
    while (parser.i < parser.nb_l) {
        parser.tab[parser.i] = malloc(sizeof(char) * parser.length + 1);
        while (parser.k < parser.length) {
            parser.tab[parser.i][parser.k] = parser.str1[parser.j];
            parser.j++;
            parser.k++;
        }
        parser.j++;
        parser.length = my_strlen_for_parser(parser.str1, chara, parser.j);
        parser.tab[parser.i][parser.k] = '\0';
        parser.k = 0;
        parser.i++;
    }
    parser.tab[parser.i] = NULL;
    return (parser);
}

char **my_parser(char *str, char chara)
{
    parser_t parser;
    parser.i = 0;
    parser.j = 0;
    parser.k = 0;
    parser.str1 = str_delete(str, chara);
    parser.length = my_strlen_for_parser(parser.str1, chara, parser.j);
    parser.nb_l = str_nb_chara(parser.str1, chara);
    parser.tab = malloc(sizeof(char *) * parser.nb_l + 0);

    if (error_parser(str, chara) == 1)
        return (NULL);
    if (error_parserbis(str, chara) != NULL)
        return (error_parserbis(str, chara));
    parser = my_parser_bis(parser, chara);
    return (parser.tab);
}

// int main(int argc, char const *argv[])
// {
//     char *str = "ls    ; cd    ";
//     char *str2 = str_delete2(str);
//     // printf("%s\n", str2);
//     // str2 = str_delete(str2, ' ');
//     char **tab = my_parser(str, ';');

//     printf("%s\n", str2);
//     for (int i = 0; tab[i] != NULL; i++)
//         printf("%i = %s\n", i, tab[i]);
//     return 0;
// }
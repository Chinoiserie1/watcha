/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** include
*/

#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#ifndef READ_SIZE
#define READ_SIZE 25665885
#endif

typedef struct shell_s shell_t;
struct shell_s {
	char **tab;
	char *arg;
	int fd;
	char *str;
	char **comd;
	char **cmd;
	pid_t pid;
	char *path;
	int stop;
	int ps;
	char **envp;
};

typedef struct parser_s parser_t;
struct parser_s {
	char **tab;
	int i;
	int j;
	int k;
	int length;
	int nb_l;
	char *str1;
};

typedef struct list_s list_t;
struct list_s {
	char *str;
	char **cmd2;
    list_t *next;
    list_t *before;
};

void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, const char *src);
int my_strncmp(char const *s1, char const *s2, int n);
char *tab_to_str(char **tab);
char *my_realloc(char *str);
char *get_next_line(int fd);
void process(shell_t *sh);
char **run(shell_t *sh);
shell_t *run_cmd(shell_t *sh, char **tab);
shell_t *run_f(shell_t *sh, list_t *list);
list_t *get_cmd(shell_t *sh);
void get_pid(shell_t *sh);
char **my_parser(char *str, char chara);
parser_t my_parser_bis(parser_t parser, char chara);
char *str_delete(char *str, char chara);
int error_parser(char *str, char chara);
int str_nb_chara(char *str, char chara);
int my_strlen_for_parser(char *str, char chara, int i);
void display_env(shell_t *sh);
void get_path(shell_t *sh);
char **my_cd(shell_t *sh, int *i, char **cmdt);
char *my_strcat(char *dest, const char *src);
char *get_env(char **env, char *str);
char *cut_str(char *dest, char *strc);
char **my_setenv(shell_t *sh, char *name, char *str);
char **my_unsetenv(shell_t *sh, char *str);
int nb_line(char **tab);
int my_strchr(char *str, char c);
char **error_parserbis(char *str, char c);
char *change_str(char *str);
char *my_strcpy(char const *src);
char **copy_env(char **env);
int exec_cmd(shell_t *sh, char **cmd, char **env);
char **my_strcpy_tab(char **tab);

list_t *new_list(void);
void add_element_after(list_t *element, char *str);
void print_list(list_t *first);

#endif
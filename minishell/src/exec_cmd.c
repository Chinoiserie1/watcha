/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** exec_cmd.c
*/

#include "../include/include.h"

int exec_cmd2(shell_t *sh, char **cmd, char **env, char *path)
{
    int res = 0;

    sh->pid = fork();
    if (sh->pid == 0 && path != NULL) {
        //if (access(path, F_OK | X_OK) == 0) {
            // for (int i = 0; cmd[i] != NULL; i++) {
            //     printf("%s\n", cmd[i]);
            // }
            res = execve(path, cmd, env);
            //return (res);
        //}
        exit(0);
    }
    else if (sh->pid > 0) {
        wait(NULL);
    }
    //return (res);
}

int exec_cmd(shell_t *sh, char **cmd, char **env)
{
    char *path = NULL;
    char **tab = my_parser(sh->path, ':');
    int stop = 0;

    for (int j = 0; tab[j] != NULL; j++) {
        path = my_strcat(tab[j], "/");
        path = my_strcat(path, cmd[0]);
        // printf("%s\n", path);
        if (access(path, F_OK | X_OK) == 0) {
            exec_cmd2(sh, cmd, env, path);
            return 0;
        }
    }
        write(2, cmd[0], my_strlen(cmd[0]));
        write(2, ": Command not found.\n", 22);
    return (0);
}
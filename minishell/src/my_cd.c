/*
** EPITECH PROJECT, 2018
** PSU_minishell2_2018
** File description:
** main fonction
*/

#include "../include/include.h"

char **change_env(shell_t *sh, char **env, char *str)
{
    int i = 0;
    int j = 0;
    char *s1;
    char *s2;

    while (env[i] != NULL) {
        if (my_strncmp(env[i], "PWD=", 4) == 1) {
            s1 = env[i];
            env[i] = my_strcat(env[i], "/");
            env[i] = my_strcat(env[i], str);
            s2 = get_env(env, "PWD=");
            if (access(s2, F_OK) != 0) {
                env[i] = s1;
                write(2, "Syntax Error: Invalid directory\n", 32);
            }
        }
        if (my_strncmp(env[i], "OLDPWD=", 7) == 1)
            env[i] = my_strcat("OLD", s1);
        i++;
    }
    return (env);
}

char **my_cd(shell_t *sh, int *i, char **cmdt)
{
    char *path; 
    int stop = 0;

    if (cmdt[*i + 1] == NULL) {
        write(2, "Syntax Error: no argument !\n", 28);
        stop = 1;
        return sh->envp;
    }
    if (access(my_strcat(my_strcat(get_env(sh->envp, "PWD="), "/")
    , cmdt[*i + 1]), F_OK) != 0) {
        write(2, "Syntax Error: Invalid directory\n", 32);
        stop = 1;
        return sh->envp;
    }
    if (stop != 1) {
        sh->envp = change_env(sh, sh->envp, cmdt[*i + 1]);
        path = get_env(sh->envp ,"PWD=");
        if (chdir(path) == -1)
            write(2, "Error: access fail\n", 19);
    }
    return (sh->envp);
}
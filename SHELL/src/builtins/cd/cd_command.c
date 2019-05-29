/*
** EPITECH PROJECT, 2018
** cd_command.c
** File description:
** man cd
*/

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "stdc.h"
#include "minishell_1.h"

static char	*handle_dash_param_cd_command(char *path_save, char *tmp)
{
	if (path_save == NULL)
		path_save = my_strdup("");
	if (chdir(path_save) == -1)
		perror(path_save);
	free(path_save);
	path_save = tmp;
	return (path_save);
}

static char	*replace_previous_static_dest(char *path_save, char *tmp)
{
	if (path_save != NULL)
		free(path_save);
	path_save = tmp;
	return (path_save);
}

static char	*change_dir_cd_command(char	*path_save,
					char	**env,
					char	*dir,
					char	option)
{
	char	*tmp = getcwd(NULL, 0);

	if (dir == NULL) {
		path_save = replace_previous_static_dest(path_save, tmp);
		chdir(get_env_result(env, "HOME"));
		display_cd_dest(option, env);
	}
	else if (my_strcmp(dir, "-") == 0)
		path_save = handle_dash_param_cd_command(path_save, tmp);
	else {
		path_save = replace_previous_static_dest(path_save, tmp);
		if (chdir(dir) == -1)
			handle_chdir_error_cases(dir);
		else
			display_cd_dest(option, env);
	}
	return (path_save);
}

static char	*parse_params_and_change_dir(	char **argv,
						char **env,
						char *path_save)
{
	int		i = 1;
	cd_options_t	options = {false, false, false, false, 0};

	for (i = 1 ; argv[i] != NULL ; i++) {
		if (my_strcmp(argv[i], "-p") == 0)
			options.psi = true;
		if (my_strcmp(argv[i], "-l") == 0)
			options.lambda = true;
		if (my_strcmp(argv[i], "-v") == 0)
			options.velo = true;
		if (my_strcmp(argv[i], "-n") == 0)
			options.nul = true;
		if (!is_cd_valid_arg(argv[i]))
			break;
	}
	options.final = get_option(options.psi, options.lambda,
						options.velo, options.nul);
	path_save = change_dir_cd_command(path_save, env,
						argv[i], options.final);
	return (path_save);
}

int	cd_command(char **argv, char **env)
{
	static char	*path_save = NULL;

	if (argv == NULL && env == NULL) {
		if (path_save != NULL)
			free(path_save);
		return (NORMAL_EXIT);
	}
	path_save = parse_params_and_change_dir(argv, env, path_save);
	return (KEEP_LOOPING);
}

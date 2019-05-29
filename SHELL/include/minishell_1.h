/*
** EPITECH PROJECT, 2018
** minishell_1.h
** File description:
** Header for a shell
*/

#ifndef		_MINISHELL_1_H_
#	define	_MINISHELL_1_H_

#include <stdbool.h>
#include <stdint.h>

typedef	struct all_builtins_commands_s	all_builtins_commands_t;
typedef	struct all_builtins_types_s	all_builtins_types_t;
typedef struct cd_options_s		cd_options_t;

enum	return_states {
	KEEP_LOOPING = -100,
	NORMAL_EXIT = -101,
	ERROR_EXIT = -102,
	ADD_ENV = -103,
	REMOVE_ENV= -104
};

/*
enum	redirection_types_e {
	PIPE_IN = 1,
	PIPE_OUT
};
*/

enum	bit_flags_e {
	PIPE_IN = 0x1,
	PIPE_OUT = 0x2
};

struct	all_builtins_commands_s {
	char	*command_name;
	int	(*command_fct)(char **argv, char **env);
};

struct	cd_options_s {
	bool	psi;
	bool	lambda;
	bool	nul;
	bool	velo;
	char	final;
};

static int const BUILTINS_NB = 4;

int	env_command(char **argv, char **env);
int	cd_command(char **argv, char **env);
int	setenv_command(char **argv, char **env);
int	unsetenv_command(char **argv, char **env);
char	*get_env_result(char **env, char *selection);
int	my_execvpe(char *file, char **argv, char **envp);
int	shell_execute(char **argv, char ***env, uint8_t redirection);
void	sig_handler_after_command(int signal);
void	sig_handler_before_command(int signal);
bool	display_prompt_and_before(void);
char	**add_env_variable(char *variable, char *value, char **env);
char	*cpy_env_variable(char *variable);
all_builtins_commands_t	*init_tab_builtins(all_builtins_commands_t *);
bool	check_user_permissions(char *file, char **argv, char **envp);
char	*read_line_and_format_it(char **env);
void	display_cd_dest(char option, char **env);
char	get_option(bool n, bool v, bool p, bool l);
bool	is_cd_valid_arg(char *arg);
char	*transform_dollar_variables(char *line, char **env);
int	shell_loop(char ***ev);
int	shell_launch(all_builtins_commands_t	*tab_builtins,
			char			**argv,
			char			**env,
			uint8_t			redirection);
void	handle_command_echo_dollar(char **argv, int child_return_value);
char	*transform_tildes(char *line);
void	handle_chdir_error_cases(char *dir);
char	*line_formatting(char *line);
int	handle_command_line(char *line, char ***ev);
bool	is_trying_to_exec_bin(char *command);
bool	is_a_dir(char *path);

#endif /* _MINISHELL_1_H_ */

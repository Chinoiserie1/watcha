/*
** EPITECH PROJECT, 2018
** test_minishell.c
** File description:
** tests for minishell PART 1
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "minishell_1.h"
#include "minishell_tests.h"
#include "stdc.h"

void	redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(shell_execute, echo_bonjour, .init = redirect_all_std)
{
	char const	*command = "echo bonjour";
	char		**argv = my_str_to_line_array(command, ' ', 1);
	int		len = 0;
	char		*buffer = malloc(11);
	char		*buffer_2 = malloc(11);
	FILE		*stdout_2 = cr_get_redirected_stdout();

	system("echo -e \"echo bonjour\n\" | tcsh");
	len = read(stdout_2->_fileno, buffer, 100);
	buffer[len] = '\0';
	shell_execute(argv, &environ);
	len = read(stdout_2->_fileno, buffer_2, 100);
	buffer[len] = '\0';
	cr_assert_str_eq(buffer, buffer_2);
	free(buffer);
	free(buffer_2);
	free_two_dims_tab((void **)argv);
}

Test(shell_execute, setenv, .init = redirect_all_std)
{
	char	**ev_cpy = strdup_two_dims_str_tab(environ);
	char	**argv = my_str_to_line_array("setenv OUI 42\n", ' ', 1);
	char	*my_env = malloc(6001);
	FILE	*stdout_2 = cr_get_redirected_stdout();
	int	len = 0;

	shell_execute(argv, &ev_cpy);
	argv = my_str_to_line_array("env\n", ' ', 1);
	shell_execute(argv, &ev_cpy);
	len = read(stdout_2->_fileno, my_env, 6000);
	my_env[len] = '\0';
	if (!my_strstr(my_env, "OUI=42\n"))
		cr_assert_fail("Setenv FAIL\n");
	free(my_env);
	free_two_dims_tab((void **)argv);
	free_two_dims_tab((void **)ev_cpy);
}

Test(shell_execute, ls_dash_la, .init = redirect_all_std)
{
	char	**argv = my_str_to_line_array("cd -l include\n", ' ', 1);
	char	*my_env = malloc(6001);
	char	*real_env = malloc(6001);
	FILE	*stdout_2 = cr_get_redirected_stdout();
	int	len = 0;

	system("echo -e \"cd -l include\n\" | tcsh");
	len = read(stdout_2->_fileno, real_env, 6000);
	real_env[len] = '\0';
	shell_execute(argv, &environ);
	len = read(stdout_2->_fileno, my_env, 6000);
	my_env[len] = '\0';
	cr_assert_str_eq(real_env, my_env);
	free(my_env);
	free(real_env);
	free_two_dims_tab((void **)argv);
}

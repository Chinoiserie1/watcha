/*
** EPITECH PROJECT, 2018
** test_error_handling.c
** File description:
** error handling minishell_1
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

Test(shell_execute, sigfpe_core_dump, .init = redirect_all_std)
{
	char	**argv = my_str_to_line_array("./sigfpe_core_dump\n", ' ', 1);
	char	*my_result = malloc(6001);
	char	*real_result = malloc(6001);
	FILE	*stdout_2 = cr_get_redirected_stderr();
	int	len = 0;

	system("echo -e \"./sigfpe_core_dump\n\" | tcsh");
	len = read(stdout_2->_fileno, real_result, 6000);
	real_result[len] = '\0';
	shell_execute(argv, &environ);
	len = read(stdout_2->_fileno, my_result, 6000);
	my_result[len] = '\0';
	if (!my_strstr(real_result, my_result))
		cr_assert_fail("TEST sigfpe_core_dump FAIL\n");
	free(my_result);
	free(real_result);
	free_two_dims_tab((void **)argv);
}

Test(shell_execute, semi_colon, .init = redirect_all_std)
{
	char	*command = "echo Yo ; echo bonjour\n";
	int	len = 0;
	char	*buffer = malloc(100);
	char	*buffer_2 = malloc(100);
	FILE	*stdout_2 = cr_get_redirected_stdout();

	system("echo -e \"echo Yo ; echo bonjour\n\" | tcsh");
	len = read(stdout_2->_fileno, buffer, 100);
	buffer[len] = '\0';
	handle_command_line(command, &environ);
	len = read(stdout_2->_fileno, buffer_2, 100);
	buffer[len] = '\0';
	cr_assert_str_eq(buffer, buffer_2);
	free(buffer);
	free(buffer_2);
}

/*
** EPITECH PROJECT, 2018
** signal_handler.c
** File description:
** signal_handler
*/

#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include "stdc.h"
#include "minishell_1.h"

void	sig_handler_before_command(int signal)
{
	if (signal == SIGINT) {
		my_printf("\n");
		display_prompt_and_before();
	}
}

void	sig_handler_after_command(int signal)
{
	if (signal == SIGINT)
		my_printf("\n");
}

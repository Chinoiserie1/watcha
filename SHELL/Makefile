##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

CC		=	gcc

CFLAGS		=

LDFLAGS		=	-L./lib/stdc
LDLIBS		=	-lstdc

CPPFLAGS	=	-I./include -I./lib/stdc -Wall -Wextra

RM		=	rm -f

SRCS		=	src/shell_loop.c			\
			src/builtins/builtins.c			\
			src/builtins/setenv.c			\
			src/my_execvpe.c			\
			src/shell_execute_commands.c		\
			src/signal_handler.c			\
			src/check_user_permissions.c		\
			src/read_line_and_format_it.c		\
			src/builtins/cd/cd_options.c		\
			src/builtins/cd/cd_command.c		\
			src/transform_dollar_variables.c	\
			src/shell_launch.c			\
			src/echo_dollar_question_mark.c		\
			src/tilde.c				\
			src/builtins/cd/error_cases_cd.c	\
			src/is_trying_to_exec_a_bin.c

TSRCS		:=	$(SRCS)

SRCS		+=	src/main_minishell.c

OBJS		=	$(SRCS:.c=.o)

NAME		=	mysh

export

all		: $(NAME)

$(NAME)		:	$(OBJS)
		$(MAKE) -C./lib/stdc
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(LDLIBS)

tests_run	:
		$(MAKE) -C ./tests/

main_clean	:
		$(RM) $(OBJS)

debug:		CFLAGS += -g3
debug:		fclean all

clean		:
		$(RM) $(OBJS)
		$(MAKE) -C ./lib/stdc/ clean
		$(MAKE) -C ./tests/ clean

fclean		:	main_clean
		$(RM) $(NAME)
		$(MAKE) -C ./lib/stdc/ fclean
		$(MAKE) -C ./tests/ fclean

re		:
		$(MAKE) fclean --no-print-directory
		$(MAKE) all --no-print-directory

.PHONY: all clean fclean re main_clean tests_run

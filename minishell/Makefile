##
## EPITECH PROJECT, 2018
## makefile
## File description:
## simple makefile
##

SRC	=	src/main.c 					\
		src/my_putchar.c 			\
		src/my_putstr.c 			\
		src/my_strlen.c 			\
		src/process.c 				\
		src/get_pid.c 				\
		src/my_parser.c 			\
		src/my_strlen_for_parser.c 	\
		src/display_env.c 			\
		src/my_strncmp.c 			\
		src/run.c 					\
		src/get_cmd.c 				\
		src/get_path.c 				\
		src/my_strcmp.c 			\
		src/my_cd.c 				\
		src/my_strcat.c 			\
		src/tab_to_str.c 			\
		src/get_env.c 				\
		src/my_setenv.c 			\
		src/my_unsetenv.c 			\
		src/new_list.c 				\
		src/add_element_after.c 	\
		src/print_list.c 			\
		src/my_strchr.c 			\
		src/error_parser.c 			\
		src/my_strcpy.c 			\
		src/copy_env.c 				\
		src/exec_cmd.c 				\
		src/my_strcpy_tab.c 		\
		src/run2.c 					\
		src/get_next_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
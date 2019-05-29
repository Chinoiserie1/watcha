##
## EPITECH PROJECT, 2018
## Makefile_for_test_minishell
## File description:
## Tests of minishell_1.
## DO NOT LAUNCH THIS MAKEFILE DIRECTLY
## This makefile can only work if launched from the main makefile with the "test_run" command
##

TFLAGS		=	-Wextra
TFLAGS		+=	-Wall
TFLAGS		+=	--coverage

CPPFLAGS	=	-I ../include -I ./include
LDFLAGS		=	-L ../lib/stdc
LDLIBS		=	-lstdc

TSRCS_PATH	=	$(addprefix ../, $(TSRCS))

TFILE		=	test_path_env.c		\
			test_error_handling.c

TSRCS_NOTDIR	=	$(notdir $(TSRCS))
TSRCS_NOTDIR	+=	$(TFILE)

TOBJS		=	$(TSRCS_NOTDIR:c=gcno)
TOBJS		+=	$(TSRCS_NOTDIR:c=gcda)
TOBJS		+=	$(TSRCS_NOTDIR:c=c.gcov)
TOBJS		+=	$(TFILE:c=gcda)
TOBJS		+=	$(TFILE:c=gcno)
TOBJS		+=	$(TFILE:c=c.gcov)

NAME		=	tests_minishell

all		:	$(NAME)

$(NAME)		:
		$(MAKE) -C ../lib/stdc/
		$(CC) $(TFLAGS) -o $(NAME) $(CPPFLAGS) $(TSRCS_PATH) $(TFILE) $(LDFLAGS) $(LDLIBS) -lcriterion
		mv $(NAME) ../
		../$(NAME)

tests_run	:
		$(MAKE) -C ../ tests_run

clean		:
		$(RM) $(TOBJS)

fclean		:	clean
		$(RM) ../$(NAME)
		$(MAKE) -C ../lib/stdc/ fclean

re		: fclean all

.PHONY:	all clean fclean re

##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## cpy lib, cpy .h. Clean rule
##

CC		=	gcc

RM		=	rm -f

CFLAGS		=	-Wextra -Wall

CPPFLAGS	=	-I ./

NAME		=	libstdc.a

CLEAN		=	clean

HEADER		=	stdc.h

MAKE		=	make

SRCS		=	my_putchar.c		\
			my_put_nbr.c		\
			my_getnbr.c		\
			my_putstr.c		\
			my_showmem.c		\
			my_showstr.c		\
			my_strcpy.c		\
			my_strcmp.c		\
			my_strncmp.c		\
			my_strdup.c		\
			my_strndup.c		\
			my_str_isnum.c		\
			my_str_isprintable.c	\
			my_strlen.c		\
			my_atoi.c		\
			my_strupcase.c		\
			my_strlowcase.c		\
			my_strcat.c		\
			my_strncat.c		\
			print_base_8.c		\
			print_base_2.c		\
			is_operator.c		\
			my_strncpy.c		\
			my_compute_power_rec.c	\
			my_printf.c		\
			my_printf_math.c	\
			my_printf_is_flag.c	\
			my_printf_detection_1.c			\
			my_printf_go_over_flags_1.c		\
			my_printf_go_over_flags_2.c		\
			my_printf_argument_type_d_x.c		\
			my_printf_argument_type_o_b.c		\
			my_printf_argument_type_u.c		\
			my_printf_argument_type_p.c		\
			my_printf_argument_type_big_s.c		\
			my_printf_argument_type_c_s.c		\
			my_printf_argument_type_big_x.c		\
			my_printf_arg_type_lld_lu_llu.c		\
			my_printf_argument_type_lu.c		\
			my_printf_arg_type_distri.c		\
			str_add_remove_char.c			\
			str_truncate.c				\
			alloc_str.c				\
			my_strchr_index.c			\
			infin_read_str.c				\
			my_str_to_line_array.c				\
			my_putstr_err.c					\
			two_dims_str_tab/free_two_dims_tab.c		\
			two_dims_str_tab/get_size_two_dims_tab.c	\
			get_next_line.c					\
			two_dims_str_tab/strdup_two_dims_str_tab.c	\
			two_dims_str_tab/realloc_two_dims_str_tab.c	\
			two_dims_str_tab/get_index_two_dims_tab.c	\
			two_dims_str_tab/remove_str_from_two_dims_tab.c	\
			add_str_inside_str.c				\
			my_itoa.c					\
			my_revstr.c					\
			my_str_isalpha.c				\
			my_str_is_alphanumeric.c			\
			my_strstr.c					\
			my_str_cut_word_double_quote.c

OBJS		=	$(SRCS:.c=.o)

all		:
		$(MAKE) header_move --no-print-directory

$(NAME)		:	$(OBJS)
		ar rcs $(NAME) $(OBJS) 

header_move	:
		cp $(HEADER) ../../include/
		$(MAKE) $(NAME)

clean		:
		@$(RM) $(OBJS)

fclean		:	clean
		@$(RM) ../../include/$(HEADER)
		@$(RM) $(NAME)

re		:	fclean all

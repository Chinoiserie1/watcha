/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** A bunch of standard fonctions
*/

#ifndef MY_H_
# define MY_H_

#ifndef READ_SIZE
#	define READ_SIZE	4
#endif /* READ_SIZE */

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

static const unsigned int	amount_of_types_g = 11;
static const int		buffer_size_g = 1024;
static const int		EXIT_ERROR = 84;
static const unsigned char	new_line_g = '\n';
static const char		NEW_LINE = '\n';

/*
** My printf structures
*/
typedef	struct all_types_s	all_types_t;
typedef struct all_flags_s	all_flags_t;
typedef struct dest_src_s	dest_src_t;

struct all_flags_s {
	unsigned int	field_width;
	unsigned int	blank_or_zero;
	unsigned int	base;
	unsigned int	left_justify;
	unsigned int	display_number_sign;
	unsigned int	blank_flag;
	unsigned int	prefix_flag;
	int		precision;
};

struct	all_types_s {
	char	type;
	void	(*display_type_fct)(va_list, all_flags_t *);
};

struct	dest_src_s {
	char		*str;
	char const	*to_find;
};

enum	all_bases {
	BASE_16,
	BASE_10,
	BASE_8,
	BASE_2
};

enum	display_blank_or_zero {
	BLANK,
	ZERO
};

enum	yes_no {
	YES,
	NO
};

void	my_putchar(char c);
void	my_putchar_err(char c);
int	my_put_nbr(int nb);
int	my_put_nbr_long_long(long long nb);
void	my_swap(int *a, int *b);
int	my_putstr(char const *str);
void	my_putstr_err(char *str);
int	my_putnstr(char *str, unsigned int n);
int	my_strlen(char const *str);
int	my_strnlen(char const *str, int n);
int	my_getnbr(char const *str);
char	*my_strcpy(char *dest, char const *src);
char	*my_strncpy(char *dest, char const *src, int n);
int	my_str_isnum(char const *str);
int	my_str_isprintable(char const *str);
int	my_showstr(char const *str);
int	my_showmem(char const *str, int size);
char	*my_strdup(char const *src);
char	*my_strndup(char const *str, size_t n);
int	my_strcmp(char const *s1, char const *s2);
int	my_strncmp(char const *s1, char const *s2, int nb);
int	my_compute_power_rec(int nb, int p);
char	*my_strlowcase(char *str);
char	*my_strupcase(char *str);
char	*my_strcat(char *dest, char const *src);
char	*my_strncat(char *dest, char const *src, int nb);
char	*my_revstr(char *str);
int	my_str_isalpha(char const *str);
bool	my_str_is_alphanumeric(char const *str);
char	*my_strstr(char *str, char const *to_find);

/*
** my_printf
*/
int	my_printf(char const *format, ...);
int	is_a_field_width_option(char c);
int	is_an_argument_type(char c);
int	is_a_flag_option(char c);
int	display_char_and_execute_modulo(char const *format, unsigned int *i,
					va_list ap);
int	detect_and_execute_flag(char const *format, unsigned int *index,
				va_list ap);
int	check_for_hashkey(char const *format, unsigned int i, va_list ap);
int	print_argument(char argument_type, va_list ap, all_flags_t *all_flags);
int	print_blank(int mode, int amout_of_blank);
all_flags_t	*initialisation_all_flags(all_flags_t *allflags);
all_flags_t	*setup_flags(char c, all_flags_t *all_flags);
int	go_over_flags(char const *format, int i, all_flags_t *all_flags);
void	print_argument_d(va_list ap, all_flags_t *all_flags);
void	print_before_just_before_argument_d(int nb, all_flags_t *all_flags,
						unsigned int width);
char	get_number_sign(int nb);
unsigned int	get_nbr_size(int nb, unsigned int base_received);
void	print_argument_x(va_list ap, all_flags_t *all_flags);
void	print_argument_big_x(va_list ap, all_flags_t *all_flags);
void	print_before_just_before_argument_x(int nb, all_flags_t *all_flags,
						unsigned int width);
void	print_argument_o(va_list ap, all_flags_t *all_flags);
void	print_before_just_before_argument_o(int nb, all_flags_t *all_flags,
						unsigned int width);
void	print_argument_u(va_list ap, all_flags_t *all_flags);
void	print_before_just_before_argument_u(int nb, all_flags_t *all_flags,
						unsigned int width);
void	print_argument_p(va_list ap, all_flags_t *all_flags);
void	print_before_just_before_argument_p(long long nb,
						all_flags_t *all_flags,
						unsigned int width);
void	print_argument_b(va_list ap, all_flags_t *all_flags);
void	print_before_just_before_argument_b(int nb, all_flags_t *all_flags,
						unsigned int width);
void	print_argument_big_s(va_list ap, all_flags_t *all_flags);
void	my_showstr_octal(char *str);
void	print_backslash_zero_octal(char c);
void	print_argument_s(va_list ap, all_flags_t *all_flags);
void	print_other_argument(char argument_type, va_list ap,
				all_flags_t *all_flags);
void	print_other_argument_2(char argument_type, va_list ap,
				all_flags_t *all_flags);
int	go_over_argument_type(char const *format, int i,
				all_flags_t *all_flags, va_list ap);
int	go_over_field_width_options(char const *format, int i,
					all_flags_t *all_flags);
void	print_argument_lld(va_list ap, all_flags_t *all_flags);
void	print_before_just_before_argument_lld(long long nb,
				all_flags_t *all_flags, unsigned int width);
void	print_before_just_before_argument_llu(long long nb,
				all_flags_t *all_flags, unsigned int width);
void	print_argument_llu(va_list ap, all_flags_t *all_flags);
void	print_argument_lu(va_list ap, all_flags_t *all_flags);
void	print_before_just_before_argument_lu(long nb,
				all_flags_t *all_flags, unsigned int width);
void	print_argument_c(va_list ap, all_flags_t *all_flags);
void	execute_flag(char argument_type, all_types_t *tab_all_types,
				va_list ap, all_flags_t *all_flags);
all_types_t	*initialisation_tab_types(all_types_t *tab_all_types);
all_types_t	*initialisation_tab_types_2(all_types_t	*tab_all_types);
int	handle_case_long_long(char const *format, int *i_2,
				va_list ap, all_flags_t *all_flags);
int	print_multiple_l(int i, int i2);
int	display_long_d(char const *format, int *i2,
			va_list ap, all_flags_t *all_flags);
int	display_long_u(char const *format, int *i2,
			va_list ap, all_flags_t *all_flags);
void	print_base_16_advanced_64_bits(long long nb);
void	print_base_16_super_advanced_64(unsigned long long nb);
/*
** Custom ones
*/
int	is_space(char c);
int	is_number_base_10(char c);
int	update_start(int start, int i);
void	reset_i2_start(int *i2, int *start);
int	is_printable(char c);
void	print_backslash_zero(char c);
void	my_putnstr_printable(char const *str, unsigned int n, int i2, int size);
void	print_two_letters(char a, char b, int i2, int size);
char    *my_realloc_str(char *str, size_t new_size);
char	*my_recalloc_str(char *str, size_t new_size);
char	*my_calloc_str(size_t new_size);
char	*new_string_fct(size_t size);
char	*add_char_to_str(char *str, char c, int index);
char	*remove_char_from_str(char *str, int index);
char	*truncate_str(char const *str, int index1 , int index2);
int	check_not_same_size(char const *smaller_str,
				char const *s1, char const *s2, int i);
char const	*get_smaller_str(char const *s1, char const *s2);
char const	*get_longest_str(char const *s1, char const *s2);
int		my_strchr_index(char const *str, char c);
char		*get_str_from_filename(char *filename);
char		*infin_read_str(FILE *map);
char		*end_the_loop_read_str(	char	*str,
					size_t	size,
					int	*first_loop,
					int	read_char);
unsigned int	calc_amount_line(char const *str, char delim, int option);
unsigned int	get_index_new_line(char const *str, unsigned int i, char);
char		**my_str_to_line_array(char const *str, char delim, int option);
void		*free_two_dims_tab(void **tab);
int		get_size_two_dims_tab(void **tab);
char		*my_strcat_alloc(char *dest, char const *src);
char	**strdup_two_dims_str_tab(char **tab);
char	**realloc_two_dims_str_tab(char **tab, size_t size);
int	get_index_two_dims_tab(char **tab, char *str);
char	**remove_str_from_two_dims_tab(char **tab, int index);
char	*add_str_inside_str(char *dest, char *src, int index);
bool	is_letter(char c);
char	**my_str_cut_word_double_quote(char const *str_origin,
						char const *delim, int option);
char	**init_grid(unsigned int lines_nb);
char	*remove_chars_from_str(char *str, char to_remove);

/*
** Base print
*/
void	print_base_16(int nb);
void	print_base_16_advanced(int nb);
void	print_base_16_super_advanced(unsigned long nb);
char	associate_base_16(char remainder);
char	associate_base_16_2(char remainder);
void	print_base_8_advanced(int nb);
void	print_base_8_super_advanced(unsigned long nb);
void	print_base_10_negativ_nbr_without_neg_sign(int nb);
void	print_base_10_without_neg_sign_advanced(unsigned long nb);
void	print_base_2_advanced(int nb);
void	print_base_2_super_advanced(unsigned long nb);
void	print_longlong_negativ_nbr_without_neg_sign(long long nb);
void	print_longlong_without_neg_sign_advanced(unsigned long long nb);
void	print_base_16_advanced_caps(int nb);
void	print_base_16_super_advanced_caps(unsigned long nb);
char	associate_base_16_caps(char remainder);
char	associate_base_16_2_caps(char remainder);

/*
** Extra ones
*/
char	*my_strndup(char const *str, size_t n);
int	my_atoi(char const *str);
char	*my_itoa(int x);
char	*get_next_line(int fd);

#endif

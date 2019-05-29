/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** read next line of the parameter file descriptor
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "stdc.h"

static char	*read_next_n_bytes(int fd, int n)
{
	char	*read_str = malloc(n + 1);
	int	len = 0;

	if (read_str == NULL)
		return (NULL);
	len = read(fd, read_str, n);
	if (len == -1) {
		free(read_str);
		return (NULL);
	}
	if (len == 0) {
		free(read_str);
		return (NULL);
	}
	read_str[len] = '\0';
	return (read_str);
}

static char	*update_remaining_str(char *read_str, int new_line_index)
{
	char	*remaining_str = NULL;

	if (read_str[new_line_index + 1] != '\0') {
		remaining_str = malloc(READ_SIZE + 1);
		remaining_str = my_strcpy(remaining_str,
						read_str + new_line_index + 1);
	}
	free(read_str);
	return (remaining_str);
}

static char	*get_line_and_remainin(	int	fd,
					int	n,
					char	**returned_line,
					int	off)
{
	char	*read_str = malloc(1);
	int	new_line_index = -1;
	char	*tmp = *returned_line;
	int	i = 1;

	while (new_line_index == -1) {
		free(read_str);
		read_str = read_next_n_bytes(fd, n);
		if (read_str == NULL) {
			*returned_line = NULL;
			return (NULL);
		}
		new_line_index = my_strchr_index(read_str, NEW_LINE);
		tmp = my_realloc_str(tmp, (i * READ_SIZE + off) + 1);
		tmp = my_strcat(tmp, read_str);
		if (new_line_index != -1)
			tmp[new_line_index + READ_SIZE * (i - 1) + off] = '\0';
		i += 1;
	}
	*returned_line = tmp;
	return (update_remaining_str(read_str, new_line_index));
}

char	*case_read_enough(char **offset, int new_line_index)
{
	char	*line = NULL;
	char	*tmp = NULL;

	tmp = malloc(READ_SIZE + 1);
	if (tmp == NULL)
		return (NULL);
	tmp = my_strcpy(tmp, *offset + new_line_index + 1);
	line = my_strdup(*offset);
	if (line == NULL)
		return (NULL);
	line[new_line_index] = '\0';
	free(*offset);
	*offset = tmp;
	return (line);
}

/*
** Do not work if the line does not end with '\n'
*/
char	*get_next_line(int fd)
{
	char		*line = NULL;
	static char	*offset = NULL;
	int		new_line_index = 0;
	int		size_offset = 0;

	if (offset) {
		new_line_index = my_strchr_index(offset, NEW_LINE);
		if (new_line_index != -1) {
			line = case_read_enough(&offset, new_line_index);
			return (line);
		}
		line = my_strdup(offset);
	}
	if (offset != NULL)
		size_offset = my_strlen(offset);
	offset = get_line_and_remainin(fd, READ_SIZE, &line, size_offset);
	return (line);
}

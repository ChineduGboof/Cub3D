/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:38:52 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/13 19:52:12 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

size_t	get_line_length(char *line)
{
	size_t	count;
	size_t	index;

	index = 0;
	count = 0;
	while (line[index] != '\n' && line[index] != '\0')
	{
		index++;
		count++;
	}
	if (line[index] == '\n')
		count++;
	return (count);
}

char	*increase_str_alloc_and_cat(char **string,
		size_t increase_amount, char *src, size_t *current_s_size)
{
	char			*temporary;

	if (!(*string))
	{
		*current_s_size = 1;
		*string = gnl_custom_calloc(*current_s_size
				+ increase_amount, sizeof(char));
		if (*string == NULL)
			return (NULL);
		(*current_s_size) += increase_amount;
		gnl_ft_strlcat(*string, src, *current_s_size);
		return (*string);
	}
	temporary = gnl_ft_strdup(*string);
	free(*string);
	*string = gnl_custom_calloc((*current_s_size) + increase_amount, sizeof(char));
	if (*string == NULL)
		return (NULL);
	(*current_s_size) += increase_amount;
	gnl_ft_strlcat(*string, temporary, *current_s_size);
	free(temporary);
	gnl_ft_strlcat(*string, src, *current_s_size);
	return (*string);
}

bool	terminate_securely(char *current_line, char **buffer)
{
	free(current_line);
	free(*buffer);
	*buffer = NULL;
	return (true);
}

char	*read_until_next_line(char **current_line,
			t_buffer *buffer, ssize_t *read_status, int fd)
{
	while (!gnl_has_element(*current_line, '\n'))
	{
		*read_status = read(fd, buffer->buffer, BUFFER_SIZE);
		if (*read_status == -1
			&& terminate_securely(*current_line, &(buffer->buffer)))
			return (NULL);
		(buffer->buffer)[*read_status] = '\0';
		buffer->buf_i = 0;
		if (*read_status == 0)
			break ;
		if (increase_str_alloc_and_cat(current_line,
				*read_status, buffer->buffer,
				&(buffer->current_s_size)) == NULL)
			return (NULL);
	}
	return (*current_line);
}

char	*get_next_line(int fd)
{
	static t_buffer	buf[1024] = {0};
	char			*current_line;
	size_t			current_line_length;

	if (fd >= 0 && buf[fd].buffer == NULL)
		buf[fd].buffer = gnl_custom_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (fd < 0 || buf[fd].buffer == NULL)
		return (NULL);
	buf[fd].read_status = 1;
	current_line_length = 0;
	current_line = NULL;
	if (!increase_str_alloc_and_cat(&current_line,
			gnl_ft_strlen(&(buf[fd].buffer[buf[fd].buf_i])),
			&(buf[fd].buffer[buf[fd].buf_i]), &(buf[fd].current_s_size)))
		return (NULL);
	if (read_until_next_line(&current_line,
			&(buf[fd]), &(buf[fd].read_status), fd) == NULL)
		return (NULL);
	current_line_length = get_line_length(current_line);
	current_line[current_line_length] = '\0';
	buf[fd].buf_i += get_line_length(&(buf[fd].buffer[buf[fd].buf_i]));
	if (current_line[0] == '\0'
		&& terminate_securely(current_line, &(buf[fd].buffer)))
		return (NULL);
	return (current_line);
}

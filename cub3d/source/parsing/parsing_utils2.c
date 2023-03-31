/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:43:28 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/31 10:52:33 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*get_new_line(char **remainder)
{
	char	*line;
	char	*temp;
	int		len;

	len = 0;
	while ((*remainder)[len] != '\n' && (*remainder)[len] != '\0')
		len++;
	if ((*remainder)[len] == '\0')
	{
		*remainder = NULL;
		return (NULL);
	}
	line = ft_substr(*remainder, 0, len);
	temp = ft_strdup(&((*remainder)[len + 1]));
	free(*remainder);
	*remainder = temp;
	return (line);
}

/*	Reads information from the map line by line */
int	get_line(int fd, char **line)
{
	static char	*remainder;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	if (bytes_read < 0)
		return (-1);
	*line = get_new_line(&remainder);
	if (!*line && !remainder)
		return (0);
	return (1);
}

/* reallocates memory when more memory is needed */
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (new_size <= old_size)
		return (ptr);
	new_ptr = malloc(new_size);
	if (!new_ptr)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

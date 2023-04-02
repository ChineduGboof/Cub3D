/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:43:28 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/02 04:20:18 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	*get_new_line(char **remainder)
{
	char	*line;
	char	*temp;
	int		len;

	len = 0;
	while (*remainder && (*remainder)[len] != '\n' && (*remainder)[len] != '\0')
		len++;
	if (*remainder && (*remainder)[len] == '\0')
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
	buffer = (char *) ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
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
		return (ft_calloc(1, new_size));
	if (new_size == 0)
	{
		if (ptr)
			free(ptr);
		return (NULL);
	}
	if (new_size <= old_size)
		return (ptr);
	new_ptr = ft_calloc(1, new_size);
	if (!new_ptr)
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

void	ft_exit_error(char *message, int fd)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	close(fd);
	exit(EXIT_FAILURE);
}

void	ft_exit_msg(char *message)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}

// static char	*ft_strcpy(char *dest, char *src)
// {
// 	size_t	index;

// 	index = 0;
// 	while (src[index] != '\0')
// 	{
// 		dest[index] = src[index];
// 		index++;
// 	}
// 	dest[index] = '\0';
// 	return (dest);
// }

char	*ft_strdup_and_trim(char *src)
{
	char	*new;
	size_t	index;
	size_t	new_index;

	if (src == NULL)
		return (NULL);
	new = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (new == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	index = 0;
	new_index = 0;
	while (src[index] != '\0')
	{
		if (src[index] != ' ' && src[index] != '\t')
		{
			new[new_index] = src[index];
			new_index++;
		}
		index++;
	}
	new[new_index] = '\0';
	return (new);
}

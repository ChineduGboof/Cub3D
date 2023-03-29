/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:52:13 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/29 20:51:59 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_exit_error(char *message)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	exit(EXIT_FAILURE);
}

size_t ft_arrlen(char **arr)
{
    size_t len = 0;
    while (arr[len] != NULL)
        len++;
    return len;
}

int	ft_isvalidint(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*get_new_line(char **remainder)
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

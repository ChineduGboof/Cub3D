/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:46:23 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/13 20:17:37 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdbool.h>

# define BUFFER_SIZE 69

struct s_buffer
{
	char	*buffer;
	size_t	buf_i;
};

typedef struct s_buffer	t_buffer;

size_t	ft_strlen(const char *s);
int		gnl_has_element(char *string, char element);
void	*gnl_custom_calloc(size_t count, size_t size);
char	*gnl_ft_strdup(char *src);
size_t	gnl_ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:40:20 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/13 19:52:12 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

struct s_buffer
{
	char	*buffer;
	size_t	buf_i;
	ssize_t	read_status;
	size_t	current_s_size;
};

typedef struct s_buffer	t_buffer;

size_t	gnl_ft_strlen(const char *s);
int		gnl_has_element(char *string, char element);
void	*gnl_custom_calloc(size_t count, size_t size);
char	*gnl_ft_strdup(char *src);
size_t	gnl_ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);

#endif
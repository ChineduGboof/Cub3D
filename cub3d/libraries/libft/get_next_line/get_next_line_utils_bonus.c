/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:40:31 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/13 20:17:18 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

size_t	gnl_ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

void	*gnl_custom_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	index;

	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (index < count)
	{
		((char *)result)[index] = '\0';
		index++;
	}
	return (result);
}

int	gnl_has_element(char *string, char element)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (element == string[index])
			return (1);
		index++;
	}
	return (0);
}

char	*gnl_ft_strdup(char *src)
{
	char	*new;
	size_t	index;

	new = malloc((gnl_ft_strlen(src) + 1) * sizeof(char));
	if (new == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	index = 0;
	while (src[index] != '\0')
	{
		new[index] = src[index];
		index++;
	}
	new[index] = '\0';
	return (new);
}

size_t	gnl_ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dstlen;
	size_t	src_index;

	if (dstsize == 0)
	{
		return (gnl_ft_strlen(src));
	}
	dstlen = gnl_ft_strlen(dst);
	index = dstlen;
	src_index = 0;
	if (dstsize - dstlen > 1 && gnl_ft_strlen(src))
	{
		while (index < (dstsize - 1) && src[src_index] != '\0')
		{
			dst[index] = src[src_index];
			src_index++;
			index++;
		}
		if (dstlen > dstsize)
			return (dstsize + gnl_ft_strlen(src));
		dst[index] = '\0';
	}
	return (dstlen + gnl_ft_strlen(src));
}

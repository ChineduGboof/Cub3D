/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:51:14 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/23 13:18:03 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dstlen;
	size_t	src_index;

	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	dstlen = ft_strlen(dst);
	index = dstlen;
	src_index = 0;
	if (dstsize - dstlen > 1 && ft_strlen(src))
	{
		while (index < (dstsize - 1) && src[src_index] != '\0')
		{
			dst[index] = src[src_index];
			src_index++;
			index++;
		}
		if (dstlen > dstsize)
			return (dstsize + ft_strlen(src));
		dst[index] = '\0';
	}
	return (dstlen + ft_strlen(src));
}

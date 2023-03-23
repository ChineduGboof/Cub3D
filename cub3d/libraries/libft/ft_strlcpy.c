/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:58:42 by oaydemir          #+#    #+#             */
/*   Updated: 2021/10/03 23:59:44 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	index;

	index = 0;
	if (dstsize > 1)
	{
		while (index < (dstsize - 1) && src[index] != '\0')
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	else if (dstsize == 1)
	{
		dst[index] = '\0';
	}
	return (ft_strlen(src));
}

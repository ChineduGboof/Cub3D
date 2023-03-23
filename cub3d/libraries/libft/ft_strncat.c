/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:43:36 by oaydemir          #+#    #+#             */
/*   Updated: 2023/01/28 22:18:19 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t	src_index;
	size_t	dst_index;

	src_index = 0;
	dst_index = ft_strlen(dst);
	while (src[src_index] && len)
	{
		dst[dst_index] = src[src_index];
		src_index++;
		dst_index++;
		len--;
	}
	dst[dst_index] = '\0';
	return (dst);
}

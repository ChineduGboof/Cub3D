/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 12:26:14 by oaydemir          #+#    #+#             */
/*   Updated: 2021/10/06 16:45:19 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	index;

	if (len == 0)
		return (dst);
	if ((uintptr_t)src < (uintptr_t)dst)
	{
		index = len - 1;
		while (index > 0)
		{
			((unsigned char *)dst)[index] = ((unsigned const char *)src)[index];
			index--;
		}
		((unsigned char *)dst)[index] = ((unsigned const char *)src)[index];
	}
	else if ((uintptr_t)dst < (uintptr_t)src)
	{
		index = 0;
		while (index < len)
		{
			((unsigned char *)dst)[index] = ((unsigned const char *)src)[index];
			index++;
		}
	}
	return (dst);
}

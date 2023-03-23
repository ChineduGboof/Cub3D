/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 12:18:13 by oaydemir          #+#    #+#             */
/*   Updated: 2021/10/03 12:24:11 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		if (((unsigned char *) s1)[index] != ((unsigned char *) s2)[index])
		{
			return (((unsigned char *) s1)[index]
			- ((unsigned char *) s2)[index]);
		}
		index++;
	}
	return (0);
}

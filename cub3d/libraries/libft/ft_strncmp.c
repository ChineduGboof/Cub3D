/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 00:01:43 by oaydemir          #+#    #+#             */
/*   Updated: 2023/01/30 21:12:22 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (!s1 || !s2)
		return (-1);
	index = 0;
	while (index < n && s1[index] != '\0' && s2[index] != '\0')
	{
		if ((unsigned char) s1[index] != (unsigned char) s2[index])
			return ((unsigned char) s1[index] - (unsigned char) s2[index]);
		index++;
	}
	if (index < n && (unsigned char) s1[index] != (unsigned char) s2[index])
		return ((unsigned char) s1[index] - (unsigned char) s2[index]);
	return (0);
}

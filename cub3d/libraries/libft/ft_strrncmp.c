/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:42:11 by oaydemir          #+#    #+#             */
/*   Updated: 2023/01/28 22:18:25 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include "libft.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	s1_index;
	size_t	s2_index;

	s1_index = ft_strlen(s1) - 1;
	s2_index = ft_strlen(s2) - 1;
	while (s1_index != SIZE_MAX && s2_index != SIZE_MAX && n > 0)
	{
		if (s1[s1_index] != s2[s2_index])
			return (s1[s1_index] - s2[s2_index]);
		s1_index--;
		s2_index--;
		n--;
	}
	if (n > 0 && s1_index == SIZE_MAX && s2_index != SIZE_MAX)
		return (-s2[s2_index]);
	else if (n > 0 && s1_index != SIZE_MAX && s2_index == SIZE_MAX)
		return (s1[s1_index]);
	return (0);
}

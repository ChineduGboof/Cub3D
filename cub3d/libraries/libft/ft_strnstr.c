/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 00:26:06 by oaydemir          #+#    #+#             */
/*   Updated: 2021/10/04 00:32:34 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_i;
	size_t	needle_i;
	size_t	needle_length;

	needle_length = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *) haystack);
	haystack_i = 0;
	needle_i = 0;
	while (haystack[haystack_i] != '\0' && haystack_i < len)
	{
		while (haystack[haystack_i] == needle[needle_i]
			&& needle[needle_i] != '\0' && haystack[haystack_i] != '\0'
			&& haystack_i < len)
		{
			needle_i++;
			haystack_i++;
		}
		if (needle[needle_i] == '\0')
			return ((char *)(&(haystack[haystack_i - needle_length])));
		haystack_i -= needle_i;
		haystack_i++;
		needle_i = 0;
	}
	return (NULL);
}

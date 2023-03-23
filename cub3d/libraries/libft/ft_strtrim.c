/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 00:33:19 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/03 20:34:32 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*clean_cut;
	size_t	b;
	size_t	e;

	clean_cut = 0;
	if (s1 && set)
	{
		b = 0;
		e = ft_strlen(s1);
		while (s1[b] && ft_strchr(set, s1[b]))
			b++;
		while (s1[e - 1] && ft_strchr(set, s1[e - 1]) && e > b)
			e--;
		clean_cut = (char *)malloc(sizeof(char) * (e - b + 1));
		if (clean_cut)
			ft_strlcpy(clean_cut, &s1[b], e - b + 1);
	}
	return (clean_cut);
}

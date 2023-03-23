/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 00:32:45 by oaydemir          #+#    #+#             */
/*   Updated: 2021/10/04 00:37:56 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;

	index = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)(&(s[ft_strlen(s)])));
	else if (s[0] == '\0')
		return (NULL);
	while (index != 0)
	{
		if (s[index] == (char) c)
			return ((char *) &(s[index]));
		index--;
	}
	if (s[index] == (char) c)
		return ((char *) &(s[index]));
	return (NULL);
}

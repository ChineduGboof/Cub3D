/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:46:53 by oaydemir          #+#    #+#             */
/*   Updated: 2023/01/25 14:26:22 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <errno.h>

static char	*ft_strcpy(char *dest, char *src)
{
	size_t	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*new;

	if (src == NULL)
		return (NULL);
	new = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (new == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strcpy(new, src);
	return (new);
}

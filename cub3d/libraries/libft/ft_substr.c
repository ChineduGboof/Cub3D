/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 00:35:44 by oaydemir          #+#    #+#             */
/*   Updated: 2023/02/08 09:57:23 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*create_empty_string(void)
{
	char	*result;

	result = malloc(1);
	if (result == NULL)
		return (NULL);
	result[0] = '\0';
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*destination;
	size_t	source_index;
	size_t	destination_index;
	size_t	destination_size;

	if (start >= ft_strlen(s))
		return (create_empty_string());
	else if (ft_strlen(s + start) < len)
		destination_size = ft_strlen(s + start) + 1;
	else
		destination_size = len + 1;
	destination = malloc(destination_size);
	if (destination == NULL || s == NULL)
		return (NULL);
	source_index = start;
	destination_index = 0;
	while (destination_index < len && s[source_index] != '\0')
	{
		destination[destination_index] = s[source_index];
		source_index++;
		destination_index++;
	}
	destination[destination_index] = '\0';
	return (destination);
}

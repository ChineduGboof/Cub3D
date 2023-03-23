/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:46:13 by oaydemir          #+#    #+#             */
/*   Updated: 2023/01/21 01:39:21 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

static int	count_separators(const char *str, char c)
{
	size_t	count;
	size_t	index;
	size_t	start_index;
	size_t	end_index;

	count = 0;
	start_index = SIZE_MAX;
	index = 0;
	while (str[index] != '\0')
	{
		if (start_index == SIZE_MAX && str[index] != c)
			start_index = index;
		if (str[index] != c)
			end_index = index;
		index++;
	}
	while (start_index < end_index && start_index != SIZE_MAX)
	{
		if (str[start_index] == c && ++count)
			while (str[start_index] == c)
				start_index++;
		else
			start_index++;
	}
	return (count);
}

static size_t	custom_strlen(char const *string, char c)
{
	size_t	length;

	length = 0;
	while (*string != '\0' && *string != c)
	{
		string++;
		length++;
	}
	return (length);
}

static char	**inner_alloc_failure_handler(char **result, size_t result_index)
{
	size_t	i;

	i = 0;
	while (i < result_index)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	result_index;
	size_t	s_index;

	result = ft_calloc(count_separators(s, c) + 2, sizeof(char *));
	if (result == NULL)
		return (NULL);
	result_index = 0;
	s_index = 0;
	while (s[s_index] != '\0')
	{
		while (s[s_index] == c)
			s_index++;
		if (s[s_index] == '\0')
			break ;
		result[result_index] = ft_substr(s, s_index,
				custom_strlen(&(s[s_index]), c));
		if (result[result_index] == NULL)
			return (inner_alloc_failure_handler(result, result_index));
		result_index++;
		s_index += custom_strlen(&(s[s_index]), c);
	}
	result[result_index] = NULL;
	return (result);
}

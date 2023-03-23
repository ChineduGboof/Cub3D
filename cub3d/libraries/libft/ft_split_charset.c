/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 18:59:34 by oaydemir          #+#    #+#             */
/*   Updated: 2023/01/28 22:14:31 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"

int	has_element(char element, char *string)
{
	int	index;

	index = 0;
	while (string[index] != '\0')
	{
		if (string[index] == element)
			return (1);
		index++;
	}
	return (0);
}

int	count_separators(char *str, char *separators)
{
	int	count;
	int	index;
	int	start_index;
	int	end_index;

	count = 0;
	start_index = -1;
	index = 0;
	while (str[index] != '\0')
	{
		if (start_index == -1 && !has_element(str[index], separators))
			start_index = index;
		if (!has_element(str[index], separators))
			end_index = index;
		index++;
	}
	while (start_index < end_index && start_index != -1)
	{
		if (has_element(str[start_index], separators) && ++count)
			while (has_element(str[start_index], separators))
				start_index++;
		else
			start_index++;
	}
	return (count);
}

int	custom_strlen(char *str, char *terminators)
{
	int	length;

	length = 0;
	while (*str != '\0' && !has_element(*str, terminators))
	{
		str++;
		length++;
	}
	return (length);
}

void	custom_strcpy(char *dest, char *src, char *terminators)
{
	while (*src != '\0' && !(has_element(*src, terminators)))
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}

char	**ft_split_charset(char *str, char *charset)
{
	int		str_index;
	int		result_length;
	char	**result;
	int		result_index;

	result_length = count_separators(str, charset) + 1;
	result = ft_calloc((result_length + 1), sizeof(char *));
	str_index = 0;
	result_index = 0;
	while (result_index < result_length)
	{
		while (has_element(str[str_index], charset))
			str_index++;
		result[result_index] = malloc((custom_strlen(&(str[str_index]),
						charset) + 1) * sizeof(char));
		custom_strcpy(result[result_index], &(str[str_index]), charset);
		str_index += custom_strlen(&(str[str_index]), charset);
		result_index++;
	}
	if (result[0][0] == '\0')
		result[0] = 0;
	result[result_index] = 0;
	return (result);
}

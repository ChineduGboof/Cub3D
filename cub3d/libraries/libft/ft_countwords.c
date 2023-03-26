/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:28:50 by gboof             #+#    #+#             */
/*   Updated: 2023/03/26 00:42:45 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	ft_countwords(const char *str, char delim)
{
	int		count;
	bool	in_word;

	count = 0;
	in_word = false;
	while (*str != '\0')
	{
		if (*str == delim)
			in_word = false;
		else if (!in_word)
		{
			in_word = true;
			count++;
		}
		str++;
	}
	return (count);
}

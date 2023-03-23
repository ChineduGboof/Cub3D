/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 17:04:39 by oaydemir          #+#    #+#             */
/*   Updated: 2021/10/06 15:58:00 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	long	result;
	int		multiplier;

	result = 0;
	multiplier = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' && ++i)
		multiplier = -multiplier;
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{	
		if (multiplier == -1 && result * 10 < result)
			return (0);
		else if (multiplier == 1 && result * 10 < result)
			return (-1);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * multiplier);
}

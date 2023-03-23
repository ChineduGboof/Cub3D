/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 11:36:16 by oaydemir          #+#    #+#             */
/*   Updated: 2021/10/06 16:42:59 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	num_len(int num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static char	*handle_zero(void)
{
	char	*result;

	result = malloc(2 * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

static void	handle_negative(size_t *result_length, long *n_holder)
{
	*result_length = num_len(*n_holder) + 1;
	*n_holder = -(*n_holder);
}

static void	convert(long *number, char *result, size_t *result_index)
{
	while (*number != 0)
	{
		result[*result_index] = '0' + (*number % 10);
		*number /= 10;
		(*result_index)--;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	size_t	result_length;
	size_t	result_index;
	long	n_holder;

	n_holder = n;
	if (n_holder < 0)
		handle_negative(&result_length, &n_holder);
	else if (n_holder == 0)
		return (handle_zero());
	else
		result_length = num_len(n_holder);
	result = malloc(result_length + 1);
	if (result == NULL)
		return (NULL);
	result_index = result_length;
	result[result_index] = '\0';
	result_index--;
	convert(&n_holder, result, &result_index);
	if (result_index == 0)
		result[result_index] = '-';
	return (result);
}

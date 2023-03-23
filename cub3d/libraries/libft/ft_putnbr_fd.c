/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:19:02 by oaydemir          #+#    #+#             */
/*   Updated: 2021/10/03 23:19:30 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	count_digits(long nb)
{
	int		count;
	long	number_holder;

	number_holder = nb;
	count = 0;
	while (number_holder != 0)
	{
		count++;
		number_holder /= 10;
	}
	return (count);
}

static void	print(char buffer[], int length, int fd)
{
	int	index;

	index = 0;
	while (index < length)
	{
		write(fd, &(buffer[index]), 1);
		index++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	buffer[10];
	int		buffer_index;
	int		number_of_digits;
	long	number_holder;

	number_holder = n;
	if (number_holder < 0)
	{
		write(fd, "-", 1);
		number_holder = -number_holder;
	}
	else if (number_holder == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	number_of_digits = count_digits(number_holder);
	buffer_index = number_of_digits - 1;
	while (buffer_index != -1)
	{
		buffer[buffer_index] = '0' + (number_holder % 10);
		number_holder /= 10;
		buffer_index--;
	}
	print(buffer, number_of_digits, fd);
}

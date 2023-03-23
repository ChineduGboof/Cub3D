/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:16:54 by oaydemir          #+#    #+#             */
/*   Updated: 2021/10/03 23:17:06 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		write(fd, &(s[index]), 1);
		index++;
	}
	write(fd, "\n", 1);
}

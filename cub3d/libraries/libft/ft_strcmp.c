/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:12:07 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/23 13:07:50 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *str1, char *str2)
{
	int		index;

	index = 0;
	while (str1[index] != '\0' && str2[index] != '\0')
	{
		if ((unsigned char)str1[index] != (unsigned char)str2[index])
			break ;
		index++;
	}
	return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}

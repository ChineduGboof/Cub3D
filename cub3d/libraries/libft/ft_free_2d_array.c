/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_2d_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 19:20:57 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/02 00:40:06 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Free 2D Array type-agnostically
void	ft_free_2d_array(void ***array, size_t length, bool is_null_terminated)
{
	size_t	index;

	if (!array || !(*array))
		return ;
	index = 0;
	if (is_null_terminated)
	{
		while ((*array)[index])
		{
			ft_cautious_free(&((*array)[index]));
			index++;
		}
	}
	else
	{
		while (index < length)
		{
			ft_cautious_free(&((*array)[index]));
			index++;
		}
	}
	ft_cautious_free_double_ptr(array);
}

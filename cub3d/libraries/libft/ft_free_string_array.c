/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_string_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:15:33 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/11 17:58:07 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_free_string_array(char ***array)
{
	size_t	index;

	if (array == NULL || *array == NULL)
		return ;
	index = 0;
	while ((*array)[index])
	{
		ft_cautious_free((void **)&((*array)[index]));
		index++;
	}
	ft_very_cautious_free((void ***)array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cautious_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:09:37 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/02 00:39:50 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_cautious_free(void **pointer)
{
	if (!pointer || !(*pointer))
		return ;
	free(*pointer);
	*pointer = NULL;
}

void	ft_cautious_free_double_ptr(void ***pointer)
{
	if (!pointer || !(*pointer))
		return ;
	free(*pointer);
	*pointer = NULL;
}

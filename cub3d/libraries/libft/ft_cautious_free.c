/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cautious_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:09:37 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/02 01:22:00 by oaydemir         ###   ########.fr       */
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

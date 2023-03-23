/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cautious_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:09:37 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/11 15:58:22 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_cautious_free(void **pointer)
{
	free(*pointer);
	*pointer = NULL;
}

void	ft_very_cautious_free(void ***pointer)
{
	free(*pointer);
	*pointer = NULL;
}

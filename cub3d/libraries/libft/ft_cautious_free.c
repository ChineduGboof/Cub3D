/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cautious_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:09:37 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/26 19:34:37 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_cautious_free(void **pointer)
{
	free(*pointer);
	*pointer = NULL;
}

void	ft_cautious_free_double_ptr(void ***pointer)
{
	free(*pointer);
	*pointer = NULL;
}

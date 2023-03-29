/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:55:05 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/29 23:11:12 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

t_color	int_to_color(int source_color)
{
	t_color	color;

	color.transparency = (source_color >> 24) & 0xFF;
	color.red = (source_color >> 16) & 0xFF;
	color.green = (source_color >> 8) & 0xFF;
	color.blue = source_color & 0xFF;
	return (color);
}

t_color	unsigned_int_to_color(unsigned int source_color)
{
	t_color	color;

	color.transparency = (source_color >> 24) & 0xFF;
	color.red = (source_color >> 16) & 0xFF;
	color.green = (source_color >> 8) & 0xFF;
	color.blue = source_color & 0xFF;
	return (color);
}

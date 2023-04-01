/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:35:47 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 17:54:10 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

// Paint specified row range of the image to the specified color.
void	paint_image(t_image *image, t_color color, int y_start, int y_end)
{
	int		y_index;
	int		x_index;
	t_pixel	pixel;

	y_index = y_start;
	while (y_index < y_end)
	{
		x_index = 0;
		while (x_index < image->width)
		{
			pixel.x = x_index;
			pixel.y = y_index;
			pixel.color = color;
			put_pixel_into_image(image, pixel);
			x_index++;
		}
		y_index++;
	}
}

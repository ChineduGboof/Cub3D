/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_into_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:08:43 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/23 21:55:04 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

static	int	get_pixel_index(t_image *image, t_pixel pixel)
{
	short	chars_per_pixel;

	chars_per_pixel = image->bits_per_pixel / 8;
	return ((pixel.y * image->line_length) + (pixel.x * chars_per_pixel));
}

void	put_pixel_into_image(t_image *image, t_pixel pixel)
{
	char	*destination;

	destination = &(image->pixels[get_pixel_index(image, pixel)]);
	((unsigned char *)destination)[0] = pixel.color.blue;
	((unsigned char *)destination)[1] = pixel.color.green;
	((unsigned char *)destination)[2] = pixel.color.red;
}
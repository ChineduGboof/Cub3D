/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:52:21 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/23 17:30:19 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

t_image	*create_image(void *mlx, int width, int height)
{
	t_image	*image;

	image = ft_calloc(1, sizeof(t_image));
	if (!image)
		return (NULL);
	image->image = mlx_new_image(mlx, width, height);
	image->pixels = mlx_get_data_addr(image->image, &image->bits_per_pixel,
			&image->line_length, &image->endian);
	image->width = width;
	image->height = height;
	return (image);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 04:21:33 by gboof             #+#    #+#             */
/*   Updated: 2023/03/26 04:21:48 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <mlx.h>
# include <libft.h>

// unsigned chars inside this struct are treated as normal integers.
typedef struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_color;

typedef struct	s_pixel
{
	double			x;
	double			y;
	t_color			color;
} t_pixel;

typedef struct	s_image
{
	void	*image;
	char	*pixels;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
	int		width;
	int		height;
} t_image;


t_image			*create_image(void *mlx, int width, int height);
void			put_pixel_into_image(t_image *image, t_pixel pixel);

#endif
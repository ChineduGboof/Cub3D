/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:50:52 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/23 17:30:01 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <mlx.h>
# include <libft.h>

typedef struct s_color
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}	t_color;

typedef struct	s_pixel
{
	unsigned int	x;
	unsigned int	y;
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
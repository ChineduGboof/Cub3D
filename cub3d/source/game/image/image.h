/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 04:21:33 by gboof             #+#    #+#             */
/*   Updated: 2023/03/28 08:40:20 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <mlx.h>
# include <libft.h>

// unsigned chars inside this struct are treated as normal integers.
// temporarily changed the unsigned chars to int so that I can initialize
// the values to a -1 or 256, and use that to check if that color was allocated
// we are not given the transparency in the map so i dont think its needed
typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
	int	transparency;
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
t_image			*import_image(void *mlx_ptr, char *relative_path);

t_color			int_to_color(int source_color);
t_color			unsigned_int_to_color(unsigned int source_color);

int				get_pixel_index(t_image *image, t_pixel pixel);

void			put_pixel_into_image(t_image *image, t_pixel pixel);

#endif
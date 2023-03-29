/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:50:44 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/29 13:53:36 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include "raycasting_local.h"

void	determine_drawing_range(t_drawing_range *drawing_range, int line_height)
{
	drawing_range->start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (drawing_range->start < 0)
		drawing_range->start = 0;
	drawing_range->end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (drawing_range->end >= WINDOW_HEIGHT)
		drawing_range->end = WINDOW_HEIGHT - 1;
}

void	determine_texture_point_x(int *texture_point_x, double wall_hit_location, int current_texture_width, t_wall_hit_direction wall_hit_direction, t_vector ray_direction)
{
	*texture_point_x = wall_hit_location * ((double)(current_texture_width));
	if (((wall_hit_direction == EAST || wall_hit_direction == WEST) && ray_direction.x > 0)
		|| ((wall_hit_direction == NORTH || wall_hit_direction == SOUTH) && ray_direction.y < 0))
		*texture_point_x = current_texture_width - *texture_point_x - 1;
}

void	draw_vertical_line(double wall_hit_location, t_wall_hit_direction wall_hit_direction, t_drawing_range drawing_range, t_image *image, t_image *current_texture, t_vector ray_direction, int line_height, int x_index)
{
	double	texture_point_y_addend;
	double	texture_point_y_double;
	int		y_index;
	t_point	texture_point;
	t_pixel	pixel;
	
	determine_texture_point_x(&texture_point.x, wall_hit_location, current_texture->width, wall_hit_direction, ray_direction);
	texture_point_y_addend = 1.0 * current_texture->height / line_height;
	texture_point_y_double = (drawing_range.start - WINDOW_HEIGHT / 2 + line_height / 2) * texture_point_y_addend;
	y_index = drawing_range.start;
	while (y_index < drawing_range.end)
	{
		texture_point.y = ((int)texture_point_y_double) & (current_texture->height - 1);
		texture_point_y_double += texture_point_y_addend;
		pixel.x = x_index;
		pixel.y = y_index;
		pixel.color = unsigned_int_to_color(*((unsigned int *)&(current_texture->pixels[get_pixel_index(current_texture, (t_pixel){.x = texture_point.x, .y = texture_point.y})])));
		put_pixel_into_image(image, pixel);
		y_index++;
	}
}


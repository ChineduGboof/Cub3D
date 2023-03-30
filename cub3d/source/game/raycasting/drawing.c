/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:50:44 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/30 17:05:34 by oaydemir         ###   ########.fr       */
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

void	determine_texture_point_x(int *texture_point_x, t_ray_info ray_info, int current_texture_width)
{
	*texture_point_x = ray_info.wall_hit_location * ((double)(current_texture_width));
	if (((ray_info.wall_hit_direction == EAST || ray_info.wall_hit_direction == WEST) && ray_info.ray.direction.x > 0)
		|| ((ray_info.wall_hit_direction == NORTH || ray_info.wall_hit_direction == SOUTH) && ray_info.ray.direction.y < 0))
		*texture_point_x = current_texture_width - *texture_point_x - 1;
}

void	draw_vertical_line(t_drawing_info drawing_info, t_ray_info ray_info, t_image *image, int x_index)
{
	double	texture_point_y_addend;
	double	texture_point_y_double;
	int		y_index;
	t_point	texture_point;
	t_pixel	pixel;
	
	determine_texture_point_x(&texture_point.x, ray_info, drawing_info.current_texture->width);
	texture_point_y_addend = 1.0 * drawing_info.current_texture->height / drawing_info.line_height;
	texture_point_y_double = (drawing_info.drawing_range.start - WINDOW_HEIGHT / 2 + drawing_info.line_height / 2) * texture_point_y_addend;
	y_index = drawing_info.drawing_range.start;
	while (y_index < drawing_info.drawing_range.end)
	{
		texture_point.y = ((int)texture_point_y_double) & (drawing_info.current_texture->height - 1);
		texture_point_y_double += texture_point_y_addend;
		pixel.x = x_index;
		pixel.y = y_index;
		pixel.color = unsigned_int_to_color(*((unsigned int *)&(drawing_info.current_texture->pixels[get_pixel_index(drawing_info.current_texture, (t_pixel){.x = texture_point.x, .y = texture_point.y})])));
		put_pixel_into_image(image, pixel);
		y_index++;
	}
}


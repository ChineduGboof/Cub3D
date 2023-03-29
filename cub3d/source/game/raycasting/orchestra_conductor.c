/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:05:39 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/29 13:57:33 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include "raycasting_local.h"

// The raycasting happens here
void	fill_image(t_image *image, t_game game)
{
	int								x_index;
	double							offset_from_center;
	t_ray_info						ray_info;
	t_drawing_info					drawing_info;

	x_index = 0;
	while (x_index < WINDOW_WIDTH)
	{
		offset_from_center = (2 * x_index / (double) WINDOW_WIDTH) - 1;
		ray_info.ray.direction = calculate_ray_direction(game.player, offset_from_center);

		// rounding the player position as per the guide slows down the code extremely
		ray_info.ray.position = game.player.position;

		determine_grid_spacings(&(ray_info.grid_spacings), ray_info.ray.direction);
		determine_step(&(ray_info.step), ray_info.ray.direction);
		determine_nearest_boundary_distances(&(ray_info.nearest_boundary_distances), ray_info.ray, ray_info.grid_spacings);
		
		ray_info.wall_hit_direction = send_ray(&(ray_info.ray), &(ray_info.nearest_boundary_distances), &(ray_info.grid_spacings), &(ray_info.step), game.map);
		determine_distance_to_wall(&(drawing_info.distance_to_wall), ray_info.wall_hit_direction, ray_info.nearest_boundary_distances, ray_info.grid_spacings);
		
		// calculate height of line to draw on screen
		drawing_info.line_height = (int)(WINDOW_HEIGHT / drawing_info.distance_to_wall);
		determine_drawing_range(&drawing_info.drawing_range, drawing_info.line_height);
		determine_wall_hit_location(&ray_info.wall_hit_location, ray_info.wall_hit_direction, game.player.position, ray_info.ray.direction, drawing_info.distance_to_wall);
		
		drawing_info.current_texture = choose_texture(game, ray_info.wall_hit_direction);
		draw_vertical_line(ray_info.wall_hit_location, ray_info.wall_hit_direction, drawing_info.drawing_range, image, drawing_info.current_texture, ray_info.ray.direction, drawing_info.line_height, x_index);
		x_index++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orchestra_conductor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:05:39 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 22:01:49 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include "raycasting_local.h"

void	raycasting_cockpit(t_ray_info *ray_info, t_drawing_info *drawing_info,
			t_image *image, t_game *game)
{
	drawing_info->offset_from_center = (2 * drawing_info->x_index
			/ (double) WINDOW_WIDTH) - 1;
	ray_info->ray.direction = calculate_ray_direction(
			game->player, drawing_info->offset_from_center);
	ray_info->ray.position = game->player.position;
	determine_grid_spacings(&(ray_info->grid_spacings),
		ray_info->ray.direction);
	determine_step(&(ray_info->step), ray_info->ray.direction);
	determine_nearest_boundary_distances(
		&(ray_info->nearest_boundary_distances),
		ray_info->ray, ray_info->grid_spacings);
	ray_info->wall_hit_direction = send_ray(ray_info, game->map);
	determine_distance_to_wall(&(drawing_info->distance_to_wall),
		ray_info->wall_hit_direction, ray_info->nearest_boundary_distances,
		ray_info->grid_spacings);
	drawing_info->line_height
		= (int)(WINDOW_HEIGHT / drawing_info->distance_to_wall);
	determine_drawing_range(&drawing_info->drawing_range,
		drawing_info->line_height);
	determine_wall_hit_location(ray_info, game->player.position,
		drawing_info->distance_to_wall);
	drawing_info->current_texture
		= choose_texture(*game, ray_info->wall_hit_direction);
	draw_vertical_line(*drawing_info, *ray_info, image, drawing_info->x_index);
}

// The raycasting happens here
// Notes:
// rounding the player position as per the guide slows down the code extremely
// line_height: height of line to draw on screen
void	fill_image(t_image *image, t_game game)
{
	t_ray_info						ray_info;
	t_drawing_info					drawing_info;

	drawing_info.x_index = 0;
	while (drawing_info.x_index < WINDOW_WIDTH)
	{	
		raycasting_cockpit(&ray_info, &drawing_info, image, &game);
		drawing_info.x_index++;
	}
}

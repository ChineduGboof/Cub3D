/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_detection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:49:49 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 22:29:17 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include "raycasting_local.h"

// calculate the distance projected on the camera direction 
// (Euclidean distance will give fisheye effect)
void	determine_distance_to_wall(double *distance_to_wall,
			int wall_hit_direction,
			t_nearest_boundary_distances nearest_boundary_distances,
			t_grid_spacings grid_spacings)
{
	if (wall_hit_direction == EAST || wall_hit_direction == WEST)
		*distance_to_wall = (nearest_boundary_distances.x - grid_spacings.x);
	else
		*distance_to_wall = (nearest_boundary_distances.y - grid_spacings.y);
}

void	determine_wall_hit_location(t_ray_info *ray_info,
			t_vector player_position, double distance_to_wall)
{
	if (ray_info->wall_hit_direction == EAST
		|| ray_info->wall_hit_direction == WEST)
		ray_info->wall_hit_location = player_position.y
			+ (distance_to_wall * ray_info->ray.direction.y);
	else
		ray_info->wall_hit_location = player_position.x
			+ (distance_to_wall * ray_info->ray.direction.x);
	ray_info->wall_hit_location -= floor(ray_info->wall_hit_location);
}

void	take_horizontal_step(t_ray_info *ray_info, int *wall_hit_direction)
{
	ray_info->nearest_boundary_distances.x
		+= ray_info->grid_spacings.x;
	ray_info->ray.position.x += ray_info->step.x;
	if (ray_info->step.x < 0)
		*wall_hit_direction = EAST;
	else
		*wall_hit_direction = WEST;
}

void	take_vertical_step(t_ray_info *ray_info, int *wall_hit_direction)
{
	ray_info->nearest_boundary_distances.y
		+= ray_info->grid_spacings.y;
	ray_info->ray.position.y += ray_info->step.y;
	if (ray_info->step.y < 0)
		*wall_hit_direction = SOUTH;
	else
		*wall_hit_direction = NORTH;
}

int	send_ray(t_ray_info *ray_info, int **map)
{
	bool	wall_hit;
	int		wall_hit_direction;

	wall_hit = false;
	while (!wall_hit)
	{
		if (ray_info->nearest_boundary_distances.x
			< ray_info->nearest_boundary_distances.y)
		{
			take_horizontal_step(ray_info, &wall_hit_direction);
		}
		else
		{
			take_vertical_step(ray_info, &wall_hit_direction);
		}
		if (map[(int)ray_info->ray.position.y][(int)ray_info->ray.position.x]
			> 0)
		{
			wall_hit = true;
		}
	}
	return (wall_hit_direction);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_detection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:49:49 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/29 13:52:58 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include "raycasting_local.h"

void	determine_distance_to_wall(double *distance_to_wall, t_wall_hit_direction wall_hit_direction, t_nearest_boundary_distances nearest_boundary_distances, t_grid_spacings grid_spacings)
{
	// calculate the distance projected on the camera direction (Euclidean distance will give fisheye effect!)
	if (wall_hit_direction == EAST || wall_hit_direction == WEST)
		*distance_to_wall = (nearest_boundary_distances.x - grid_spacings.x);
	else
		*distance_to_wall = (nearest_boundary_distances.y - grid_spacings.y);
}


void	determine_wall_hit_location(double *wall_hit_location, t_wall_hit_direction wall_hit_direction, t_vector player_position, t_vector ray_direction, double distance_to_wall)
{
	if (wall_hit_direction == EAST || wall_hit_direction == WEST)
		*wall_hit_location = player_position.y + (distance_to_wall * ray_direction.y);
	else
		*wall_hit_location = player_position.x + (distance_to_wall * ray_direction.x);
	*wall_hit_location -= floor(*wall_hit_location);
}

t_wall_hit_direction	send_ray(t_ray *ray, t_nearest_boundary_distances *nearest_boundary_distances, t_grid_spacings *grid_spacings, t_step *step, int **map)
{
	bool			wall_hit;
	t_wall_hit_direction		wall_hit_direction;

	wall_hit = false;
	while (!wall_hit)
	{
		if (nearest_boundary_distances->x < nearest_boundary_distances->y)
		{
			nearest_boundary_distances->x += grid_spacings->x;
			ray->position.x += step->x;
			if (step->x < 0)
				wall_hit_direction = EAST;
			else
				wall_hit_direction = WEST;
		}
		else
		{
			nearest_boundary_distances->y += grid_spacings->y;
			ray->position.y += step->y;
			if (step->y < 0)
				wall_hit_direction = SOUTH;
			else
				wall_hit_direction = NORTH;
		}
		if (map[(int)ray->position.y][(int)ray->position.x] > 0)
			wall_hit = true;
	}
	return (wall_hit_direction);
}
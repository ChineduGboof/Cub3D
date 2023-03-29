/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_step_calculations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:56:47 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/29 13:57:13 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include "raycasting_local.h"

void	determine_grid_spacings(t_grid_spacings *grid_spacings, t_vector ray_direction)
{
	grid_spacings->x = fabs(1 / ray_direction.x);
	grid_spacings->y = fabs(1 / ray_direction.y);
}

void	determine_step(t_step *step, t_vector ray_direction)
{
	if (ray_direction.x < 0)
	{
		step->x = -1;
	}
	else
	{
		step->x = 1;
	}
	if (ray_direction.y < 0)
	{
		step->y = -1;
	}
	else
	{
		step->y = 1;
	}
}

void	determine_nearest_boundary_distances(t_nearest_boundary_distances *nearest_boundary_distances, t_ray ray, t_grid_spacings grid_spacings)
{
	if (ray.direction.x < 0)
	{
		nearest_boundary_distances->x = (ray.position.x - floor(ray.position.x)) * grid_spacings.x;
	}
	else
	{
		nearest_boundary_distances->x = (ceil(ray.position.x) - ray.position.x) * grid_spacings.x;
	}
	if (ray.direction.y < 0)
	{
		nearest_boundary_distances->y = (ray.position.y - floor(ray.position.y)) * grid_spacings.y;
	}
	else
	{
		nearest_boundary_distances->y = (ceil(ray.position.y) - ray.position.y) * grid_spacings.y;
	}
}
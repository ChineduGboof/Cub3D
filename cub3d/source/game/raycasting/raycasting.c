/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:05:39 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/28 17:52:27 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include "raycasting_local.h"

t_image	*choose_texture(t_game game, t_wall_hit_direction wall_hit_direction)
{
	if (wall_hit_direction == NORTH)
		return (game.s_textures.north_wall);
	else if (wall_hit_direction == SOUTH)
		return (game.s_textures.south_wall);
	else if (wall_hit_direction == EAST)
		return (game.s_textures.east_wall);
	else if (wall_hit_direction == WEST)
		return (game.s_textures.west_wall);
	return (NULL);
}

t_vector	calculate_ray_direction(t_player player, double offset_from_center)
{
	t_vector	ray_direction;

	ray_direction.x = player.direction.x + (player.plane.x * offset_from_center);
	ray_direction.y = player.direction.y + (player.plane.y * offset_from_center);
	return (ray_direction);
}

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

void	determine_distance_to_wall(double *distance_to_wall, t_wall_hit_direction wall_hit_direction, t_nearest_boundary_distances nearest_boundary_distances, t_grid_spacings grid_spacings)
{
	// calculate the distance projected on the camera direction (Euclidean distance will give fisheye effect!)
	if (wall_hit_direction == EAST || wall_hit_direction == WEST)
		*distance_to_wall = (nearest_boundary_distances.x - grid_spacings.x);
	else
		*distance_to_wall = (nearest_boundary_distances.y - grid_spacings.y);
}

void	determine_drawing_range(t_drawing_range *drawing_range, int line_height)
{
	drawing_range->start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (drawing_range->start < 0)
		drawing_range->start = 0;
	drawing_range->end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (drawing_range->end >= WINDOW_HEIGHT)
		drawing_range->end = WINDOW_HEIGHT - 1;
}

void	determine_wall_hit_location(double *wall_hit_location, t_wall_hit_direction wall_hit_direction, t_vector player_position, t_vector ray_direction, double distance_to_wall)
{
	if (wall_hit_direction == EAST || wall_hit_direction == WEST)
		*wall_hit_location = player_position.y + (distance_to_wall * ray_direction.y);
	else
		*wall_hit_location = player_position.x + (distance_to_wall * ray_direction.x);
	*wall_hit_location -= floor(*wall_hit_location);
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
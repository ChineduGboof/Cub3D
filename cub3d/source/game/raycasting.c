/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:33:28 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/26 21:47:02 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

// Fill the image with a color
void	paint_image(t_image *image, t_color color)
{
	int		i;
	int		j;
	t_pixel	pixel;

	i = 0;
	while (i < image->height)
	{
		j = 0;
		while (j < image->width)
		{
			pixel.x = j;
			pixel.y = i;
			pixel.color = color;
			put_pixel_into_image(image, pixel);
			j++;
		}
		i++;
	}
}

// Draw a vertical line on the image
void	draw_vertical_line(t_image *image, int x, int draw_start, int draw_end, t_color color)
{
	int		y;
	t_pixel	pixel;

	y = draw_start;
	while (y < draw_end)
	{
		pixel.x = x;
		pixel.y = y;
		pixel.color = color;
		put_pixel_into_image(image, pixel);
		y++;
	}
}


// The raycasting happens here
void	fill_image(t_image *image, t_game game)
{
	int			x;
	double		offset_from_center;
	t_ray		ray;
	double		distance_to_nearest_x_boundary;
	double		distance_to_nearest_y_boundary;
	double		distance_between_x_grids;
	double		distance_between_y_grids;
	double		distance_to_wall; // distance from the camera plane to the wall
	t_step		step;
	bool		wall_hit;
	t_direction	wall_hit_direction;
	int			line_height;
	int			draw_start;
	int			draw_end;
	t_color		color;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		offset_from_center = (2 * x / (double)WINDOW_WIDTH) - 1;
		ray.direction.x = game.player.direction.x + game.player.plane.x * offset_from_center;
		ray.direction.y = game.player.direction.y + game.player.plane.y * offset_from_center;
		
		ray.position.x = game.player.position.x;
		ray.position.y = game.player.position.y;
		
		distance_to_nearest_x_boundary = 0;
		distance_to_nearest_y_boundary = 0;
		
		distance_between_x_grids = fabs(1 / ray.direction.x);
		distance_between_y_grids = fabs(1 / ray.direction.y);
		
		distance_to_wall = 0;
		
		step.x = 0;
		step.y = 0;
		
		wall_hit = false;
		wall_hit_direction = NONE;
		
		if (ray.direction.x < 0)
		{
			step.x = -1;
			distance_to_nearest_x_boundary = (ray.position.x - floor(ray.position.x)) * distance_between_x_grids;
		}
		else
		{
			step.x = 1;
			distance_to_nearest_x_boundary = (ceil(ray.position.x) - ray.position.x) * distance_between_x_grids;
		}
		
		if (ray.direction.y < 0)
		{
			step.y = -1;
			distance_to_nearest_y_boundary = (ray.position.y - floor(ray.position.y)) * distance_between_y_grids;
		}
		else
		{
			step.y = 1;
			distance_to_nearest_y_boundary = (ceil(ray.position.y) - ray.position.y) * distance_between_y_grids;
		}
		
		while (!wall_hit)
		{
			if (distance_to_nearest_x_boundary < distance_to_nearest_y_boundary)
			{
				distance_to_nearest_x_boundary += distance_between_x_grids;
				ray.position.x += step.x;
				if (step.x < 0)
					wall_hit_direction = EAST;
				else
					wall_hit_direction = WEST;
			}
			else
			{
				distance_to_nearest_y_boundary += distance_between_y_grids;
				ray.position.y += step.y;
				if (step.y < 0)
					wall_hit_direction = SOUTH;
				else
					wall_hit_direction = NORTH;
			}
			
			if (game.map[(int)ray.position.y][(int)ray.position.x] > 0)
				wall_hit = true;
		}
		// if (wall_hit_direction == EAST || wall_hit_direction == WEST)
		// 	distance_to_wall = (ray.position.x - game.player.position.x + (1 - step.x) / 2) / ray.direction.x;
		// else
		// 	distance_to_wall = (ray.position.y - game.player.position.y + (1 - step.y) / 2) / ray.direction.y;
		
		// calculate the distance projected on the camera direction (Euclidean distance will give fisheye effect!)
		if (wall_hit_direction == EAST || wall_hit_direction == WEST)
			distance_to_wall = (distance_to_nearest_x_boundary - distance_between_x_grids);
		else
			distance_to_wall = (distance_to_nearest_y_boundary - distance_between_y_grids);

		// calculate height of line to draw on screen
		line_height = (int)(WINDOW_HEIGHT / distance_to_wall);
		
		draw_start = -line_height / 2 + WINDOW_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + WINDOW_HEIGHT / 2;
		if (draw_end >= WINDOW_HEIGHT)
			draw_end = WINDOW_HEIGHT - 1;
		
		// choose wall color
		if (wall_hit_direction == NORTH)
			color = RED;
		else if (wall_hit_direction == SOUTH)
			color = GREEN;
		else if (wall_hit_direction == EAST)
			color = BLUE;
		else if (wall_hit_direction == WEST)
			color = ORANGE;
		else if (wall_hit_direction == NONE)
			color = WHITE; // should never happen

		// draw the pixels of the stripe as a vertical line
		draw_vertical_line(image, x, draw_start, draw_end, color);
		x++;
	}

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:33:28 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/27 19:04:04 by oaydemir         ###   ########.fr       */
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
	double		wall_hit_location;
	t_image		*current_texture;
	t_pixel		pixel;
	t_point		texture_point;
	double		texture_point_y_double;
	double		texture_point_y_addend;
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
		
		// rounding the player position as per the guide slows down the code extremely
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
		
		if (wall_hit_direction == EAST || wall_hit_direction == WEST)
			wall_hit_location = game.player.position.y + (distance_to_wall * ray.direction.y);
		else
			wall_hit_location = game.player.position.x + (distance_to_wall * ray.direction.x);
		wall_hit_location -= floor(wall_hit_location);
		
		if (wall_hit_direction == NORTH)
			current_texture = game.s_textures.north_wall;
		else if (wall_hit_direction == SOUTH)
			current_texture = game.s_textures.south_wall;
		else if (wall_hit_direction == EAST)
			current_texture = game.s_textures.east_wall;
		else if (wall_hit_direction == WEST)
			current_texture = game.s_textures.west_wall;

		texture_point.x = wall_hit_location * ((double)(current_texture->width));
		if (((wall_hit_direction == EAST || wall_hit_direction == WEST) && ray.direction.x > 0)
			|| ((wall_hit_direction == NORTH || wall_hit_direction == SOUTH) && ray.direction.y < 0))
			texture_point.x = current_texture->width - texture_point.x - 1;

		texture_point_y_addend = 1.0 * current_texture->height / line_height;
		texture_point_y_double = (draw_start - WINDOW_HEIGHT / 2 + line_height / 2) * texture_point_y_addend;
		int y = draw_start;
		while (y < draw_end)
		{
			texture_point.y = ((int)texture_point_y_double) & (current_texture->height - 1);
			texture_point_y_double += texture_point_y_addend;
			pixel.x = x;
			pixel.y = y;
			pixel.color = unsigned_int_to_color(*((unsigned int *)&(current_texture->pixels[get_pixel_index(current_texture, (t_pixel){.x = texture_point.x, .y = texture_point.y})])));
			// printf("%d %d %d %d\n", pixel.color.transparency, pixel.color.blue, pixel.color.green, pixel.color.red);
			// printf("drawing to coordinates")
			put_pixel_into_image(image, pixel);
			y++;
		}
		// // choose wall color
		// if (wall_hit_direction == NORTH)
		// 	color = RED;
		// else if (wall_hit_direction == SOUTH)
		// 	color = GREEN;
		// else if (wall_hit_direction == EAST)
		// 	color = BLUE;
		// else if (wall_hit_direction == WEST)
		// 	color = ORANGE;
		// else if (wall_hit_direction == NONE)
		// 	color = WHITE; // should never happen

		// draw the pixels of the stripe as a vertical line
		// draw_vertical_line(image, x, draw_start, draw_end, color);
		x++;
	}

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_local.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:28:02 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/30 17:42:31 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_LOCAL_H
# define RAYCASTING_LOCAL_H

typedef struct s_step
{
	int	x;
	int	y;
}	t_step;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_nearest_boundary_distances
{
	double	x;
	double	y;
}	t_nearest_boundary_distances;

typedef struct s_grid_spacings
{
	double	x;
	double	y;
}	t_grid_spacings;

typedef struct s_drawing_range
{
	int	start;
	int	end;
}	t_drawing_range;

typedef struct s_ray_info
{
	t_ray							ray;
	t_nearest_boundary_distances	nearest_boundary_distances;
	t_grid_spacings					grid_spacings;
	t_step							step;
	int								wall_hit_direction;
	double							wall_hit_location;
}	t_ray_info;

typedef struct s_drawing_info
{
	double							distance_to_wall;
	t_image							*current_texture;
	int								line_height;
	t_drawing_range					drawing_range;
	int								x_index;
	double							offset_from_center;
}	t_drawing_info;

void		determine_drawing_range(t_drawing_range *drawing_range,
				int line_height);
void		draw_vertical_line(t_drawing_info drawing_info,
				t_ray_info ray_info, t_image *image, int x_index);
void		determine_grid_spacings(t_grid_spacings *grid_spacings,
				t_vector ray_direction);
void		determine_step(t_step *step, t_vector ray_direction);
void		determine_nearest_boundary_distances(
				t_nearest_boundary_distances *nearest_boundary_distances,
				t_ray ray, t_grid_spacings grid_spacings);
t_vector	calculate_ray_direction(t_player player,
				double offset_from_center);
t_image		*choose_texture(t_game game, int wall_hit_direction);
void		determine_distance_to_wall(double *distance_to_wall,
				int wall_hit_direction,
				t_nearest_boundary_distances nearest_boundary_distances,
				t_grid_spacings grid_spacings);
void		determine_wall_hit_location(t_ray_info *ray_info,
				t_vector player_position, double distance_to_wall);
int			send_ray(t_ray_info *ray_info, int **map);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_local.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:28:02 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/28 17:33:32 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef enum e_wall_hit_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NONE
} t_wall_hit_direction;

typedef struct	s_step
{
	int x;
	int y;
}				t_step;

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct	s_nearest_boundary_distances
{
	double	x;
	double	y;
}				t_nearest_boundary_distances;

typedef struct	s_grid_spacings
{
	double	x;
	double	y;
}				t_grid_spacings;

typedef struct	s_drawing_range
{
	int	start;
	int	end;
}				t_drawing_range;

typedef struct	s_ray_info
{
	t_ray							ray;
	t_nearest_boundary_distances	nearest_boundary_distances;
	t_grid_spacings					grid_spacings;
	t_step							step;
	t_wall_hit_direction			wall_hit_direction;
	double							wall_hit_location;
}				t_ray_info;

typedef struct	s_drawing_info
{
	double							distance_to_wall;
	t_image							*current_texture;
	int								line_height;
	t_drawing_range					drawing_range;
}				t_drawing_info;



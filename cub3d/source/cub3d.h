/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:40:24 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/28 09:21:34 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include "game/image/image.h" // for t_color
# include <stdio.h> //for debugging

// We should adjust the window size
// according to the Macs at campus
# define WINDOW_WIDTH 1366
# define WINDOW_HEIGHT 768
// # define VALID_IDS "NO #SO #WE #EA #F #C #"
# define NO "NO "
# define SO "SO "
# define WE "WE "
# define EA "EA "
# define F "F "
# define C "C "

// The struct that the parser should return
typedef struct s_specifications
{
	char	**map;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*sprite_texture;
	t_color	floor_color;
	t_color	ceiling_color;
}	t_specifications;

/**************$ only for the raycaster $*******************/
typedef struct s_vector
{
	double x;
	double y;
} t_vector;

typedef struct s_step
{
	int x;
	int y;
} t_step;

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_ray
{
	t_vector	position;
	t_vector	direction;
} t_ray;

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NONE
} t_direction;

typedef struct s_player
{
	t_vector position;
	t_vector direction;
	t_vector plane; // the 2d raycaster version of camera plane
} t_player;

// I didn't typedef these because I want it to
// be obvious that it's a struct
struct s_textures
{
	t_image	*east_wall;
	t_image	*west_wall;
	t_image	*south_wall;
	t_image	*north_wall;
};

struct s_mlx
{
	void	*mlx;
	void	*window;
	t_image	*image;
};
/**************$ end of: only for the raycaster $*******************/

// we need this struct to contain all allocated memory
// so that we can free them on exit
typedef struct s_game
{
	t_player			player;
	struct s_textures	s_textures;
	t_specifications	specifications;
	struct s_mlx		s_mlx;
	int					**map; // temporary	
} t_game;

// interface to the main mlx loop
void	run_game(t_specifications specifications);
void	safely_terminate(t_game *game);

/**************$ error_checks $*******************/
void	validate_map_file(const char *file);
void	check_map_file_ext(char *file);
size_t 	ft_arrlen(char **arr);
int		get_line(int fd, char **line);
void	parse_specifications(int fd, t_specifications *specifications);
void	ft_exit_error(char *message);
void	init_specifications(t_specifications *specifications);
int		ft_isvalidint(const char *str);

#endif
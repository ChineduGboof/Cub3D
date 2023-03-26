/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:40:24 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/26 19:01:23 by oaydemir         ###   ########.fr       */
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
# define WINDOW_WIDTH 750
# define WINDOW_HEIGHT 500
# define VALID_IDS "NO SO WE EA F C"

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

// I didn't typedef it because I want it to
// be obvious that it's a struct
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
void	free_2d_array(char **array);
void	error_exit(char	*message);
void	validate_map(char *cub_file);
void	check_range(char **rgb);
void	check_identifiers(int fd);
/**************$ end of: error_checks $*******************/



#endif
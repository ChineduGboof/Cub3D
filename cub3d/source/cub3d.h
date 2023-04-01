/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:40:24 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/02 01:14:38 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include "game/image/image.h" // for t_color
# include <errno.h>

// We should adjust the window size
// according to the Macs at campus
# define WINDOW_WIDTH 1366
# define WINDOW_HEIGHT 768

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
	t_color	floor_color;
	t_color	ceiling_color;
}	t_specifications;

/**************$ only for the raycaster $*******************/
typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_ray
{
	t_vector	position;
	t_vector	direction;
}	t_ray;

typedef struct s_player
{
	t_vector	position;
	t_vector	direction;
	t_vector	plane;
}	t_player;

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
	int					**map;
}	t_game;

// interface to the main mlx loop
void	run_game(t_specifications specifications);

/**************$ error_checks $*******************/
void	parsing(char *argv, t_specifications *specifications);
void	init_specifications(t_specifications *specifications);
void	validate_argument(char *map_file_path);
void	parse_colors(char *map_filepath, t_specifications *specifications);
void	ft_parse_color(char *line, t_color *color, int fd);
void	parse_textures(char *map_file_path, t_specifications *specifications);
void	parse_identifier_line(const char *line,
			t_specifications *specifications, int fd);
void	parse_map(char *map_file_path, t_specifications *specifications);
void	expand_map(char *line, t_specifications *specifications,
			int map_index, int *map_size);
void	check_map_errors(char **map);
bool	has_missing_specification(char *argument);
bool	is_empty_file(char *argument);
void	free_map(t_specifications *specifications, int status);
char	*get_first_row(char **map);
bool	is_valid_fence(char *row);
bool	is_walled(int i, int j, char **map);
void	free_map_assured(char **map, char *message, int status);

/**************$ parsing utils $*******************/
int		ft_isvalidint(const char *str);
int		get_line(int fd, char **line);
char	*ft_strdup_replace_tabs_with_space(char *src);
void	ft_exit_error(char *message, int fd);
void	ft_exit_msg(char *message);
void	*ft_realloc(void *ptr, size_t old_size, size_t new_size);
size_t	ft_arrlen(char **arr);

#endif
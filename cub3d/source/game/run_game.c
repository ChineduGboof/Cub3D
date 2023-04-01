/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:21:08 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 10:27:37 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

size_t	get_map_height(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

size_t	get_map_row_width(char *row)
{
	size_t	i;

	i = 0;
	while (row[i])
		i++;
	return (i);
}

t_vector	get_player_position(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				return ((t_vector){j + 0.5, i + 0.5});
			j++;
		}
		i++;
	}
	return ((t_vector){0, 0});
}

t_vector	get_player_direction(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return ((t_vector){0, -1});
			else if (map[i][j] == 'S')
				return ((t_vector){0, 1});
			else if (map[i][j] == 'E')
				return ((t_vector){-1, 0});
			else if (map[i][j] == 'W')
				return ((t_vector){1, 0});
			j++;
		}
		i++;
	}
	return ((t_vector){0, 0});
}

t_vector	determine_plane(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return ((t_vector){-0.66, 0});
			else if (map[i][j] == 'S')
				return ((t_vector){0.66, 0});
			else if (map[i][j] == 'E')
				return ((t_vector){0, 0.66});
			else if (map[i][j] == 'W')
				return ((t_vector){0, -0.66});
			j++;
		}
		i++;
	}
	return ((t_vector){0, 0});
}


int		**debug_create_map(char **map)
{
	int		**result;
	int		i;
	int		j;

	result = ft_calloc(get_map_height(map), sizeof(int *));
	i = 0;
	while (map[i])
	{
		result[i] = ft_calloc(get_map_row_width(map[i]), sizeof(int));
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
				result[i][j] = 0;
			else if (map[i][j] == 'N')
				result[i][j] = 0;
			else if (map[i][j] == 'S')
				result[i][j] = 0;
			else if (map[i][j] == 'E')
				result[i][j] = 0;
			else if (map[i][j] == 'W')
				result[i][j] = 0;
			else
				result[i][j] = map[i][j] - '0';
			j++;
		}
		i++;
	}
	return (result);
}

void	fill_game_struct(t_game *game, t_specifications specifications)
{
	game->map = debug_create_map(specifications.map);
	game->player = (t_player){
		.position = get_player_position(specifications.map),
		.direction = get_player_direction(specifications.map),
		.plane = determine_plane(specifications.map),
	};
}

// mlx boilerplate code
void	run_game(t_specifications specifications)
{
	t_game		game;
	bool		status;

	game.specifications = specifications;
	game.s_mlx.mlx = mlx_init();
	
	game.s_mlx.image = create_image(game.s_mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game.s_mlx.window = mlx_new_window(game.s_mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!game.s_mlx.image || !game.s_mlx.window)
	{
		ft_putstr_fd("Error: failed to create window or image\n", STDERR_FILENO);
		safely_terminate(&game);
	}
	fill_game_struct(&game, specifications);
	status = load_textures(game.s_mlx.mlx, &(game.s_textures), game.specifications);
	if (status == false)
	{
		ft_putstr_fd("Error: failed to load textures\n", STDERR_FILENO);
		safely_terminate(&game);
	}
	paint_image(game.s_mlx.image, game.specifications.ceiling_color, 0, WINDOW_HEIGHT / 2);
	paint_image(game.s_mlx.image, game.specifications.floor_color, WINDOW_HEIGHT / 2, WINDOW_HEIGHT);
	fill_image(game.s_mlx.image, game);
	
	mlx_put_image_to_window(game.s_mlx.mlx, game.s_mlx.window, game.s_mlx.image->image, 0, 0);
	mlx_hook(game.s_mlx.window, ON_KEYDOWN, 0, on_keydown, &game);
	mlx_hook(game.s_mlx.window, ON_DESTROY, 0, on_destroy, &game);
	mlx_loop(game.s_mlx.mlx);
	(void)specifications;
}

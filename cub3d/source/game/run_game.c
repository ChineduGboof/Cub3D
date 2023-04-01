/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:21:08 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/30 17:54:18 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

int		**debug_create_map(int map[mapWidth][mapHeight])
{
	int		**result;
	int		i;
	int		j;

	result = malloc(sizeof(int *) * mapHeight);
	i = 0;
	while (i < mapHeight)
	{
		result[i] = malloc(sizeof(int) * mapWidth);
		j = 0;
		while (j < mapWidth)
		{
			result[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

void	fake_fill_game_struct(t_game *game)
{
	game->map = debug_create_map(worldMap);
	game->player = (t_player){
		.position = {10.5, 9.5},
		.direction = {-1.0, 0.0},
		.plane = {0.0, 0.66}
	};
	game->specifications.east_texture = ft_strdup("./textures/xpm/BookshelfD.xpm");
	game->specifications.west_texture = ft_strdup("./textures/xpm/RedwallL.xpm");
	game->specifications.north_texture = ft_strdup("./textures/xpm/SteelwallswitchonD.xpm");
	game->specifications.south_texture = ft_strdup("./textures/xpm/WoodbrickD.xpm");
	game->specifications.floor_color = GRAY;
	game->specifications.ceiling_color = CYAN;
}

// mlx boilerplate code
void	run_game(t_specifications specifications)
{
	t_game		game;
	bool		status;

	game.specifications = specifications;
	game.s_mlx.mlx = mlx_init();
	game.s_mlx.image
		= create_image(game.s_mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game.s_mlx.window = mlx_new_window(
		game.s_mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!game.s_mlx.image || !game.s_mlx.window)
	{
		ft_putstr_fd("Error: failed to create window or image\n", STDERR_FILENO);
		safely_terminate(&game);
	}
	// fill_game_struct(&game, specifications);
	fake_fill_game_struct(&game);
	status = load_textures(
		game.s_mlx.mlx, &(game.s_textures), game.specifications);
	if (status == false)
	{
		ft_putstr_fd("Error: failed to load textures\n", STDERR_FILENO);
		safely_terminate(&game);
	}
	paint_image(game.s_mlx.image,
		game.specifications.ceiling_color, 0, WINDOW_HEIGHT / 2);
	paint_image(game.s_mlx.image,
		game.specifications.floor_color, WINDOW_HEIGHT / 2, WINDOW_HEIGHT);
	fill_image(game.s_mlx.image, game);
	mlx_put_image_to_window(game.s_mlx.mlx,
		game.s_mlx.window, game.s_mlx.image->image, 0, 0);
	mlx_hook(game.s_mlx.window, ON_KEYDOWN, 0, on_keydown, &game);
	mlx_hook(game.s_mlx.window, ON_DESTROY, 0, on_destroy, &game);
	mlx_loop(game.s_mlx.mlx);
	(void)specifications;
}

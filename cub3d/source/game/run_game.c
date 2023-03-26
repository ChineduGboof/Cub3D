/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:21:08 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/26 19:47:57 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
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
		.position = {22.0, 12.0},
		.direction = {-1.0, 0.0},
		.plane = {0.0, 0.66}
	};
}

// mlx boilerplate code
void	run_game(t_specifications specifications)
{
	t_game		game;

	
	game.s_mlx.mlx = mlx_init();
	game.s_mlx.image = create_image(game.s_mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	game.s_mlx.window = mlx_new_window(game.s_mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub1d");
	if (!game.s_mlx.image || !game.s_mlx.window)
	{
		ft_putstr_fd("Error: failed to create window or image", STDERR_FILENO);
		return ;
	}
	// fill_game_struct(&game, specifications);
	fake_fill_game_struct(&game);
	// fake_fill_image(game.s_mlx.image, BLUE);
	fill_image(game.s_mlx.image, game);
	
	mlx_put_image_to_window(game.s_mlx.mlx, game.s_mlx.window, game.s_mlx.image->image, 0, 0);
	mlx_hook(game.s_mlx.window, ON_KEYDOWN, 0, on_keydown, &game);
	mlx_hook(game.s_mlx.window, ON_DESTROY, 0, on_destroy, &game);
	mlx_loop(game.s_mlx.mlx);
	(void)specifications;
}

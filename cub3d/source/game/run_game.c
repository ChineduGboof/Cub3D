/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 23:21:08 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 21:56:42 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	fill_game_struct(t_game *game, t_specifications specifications)
{
	game->map = convert_map(specifications.map);
	game->player = (t_player){
		.position = get_player_position(specifications.map),
		.direction = get_player_direction(specifications.map),
		.plane = determine_plane(specifications.map),
	};
	ft_free_2d_array((void ***)(&(specifications.map)), 0, true);
}

// mlx boilerplate code
void	run_game(t_specifications specifications)
{
	t_game		game;
	bool		status;

	game.specifications = specifications;
	game.s_mlx.mlx = mlx_init();
	game.s_mlx.image = create_image(
			game.s_mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game.s_mlx.window = mlx_new_window(
			game.s_mlx.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!game.s_mlx.image || !game.s_mlx.window)
		terminate_with_message(&game, "Error: failed to create window\n", 10);
	fill_game_struct(&game, specifications);
	status = load_textures(game.s_mlx.mlx, &(game.s_textures),
			game.specifications);
	if (status == false)
		terminate_with_message(&game, "Error: failed to load textures\n", 11);
	refresh_display(&game);
	mlx_hook(game.s_mlx.window, ON_KEYDOWN, 0, on_keydown, &game);
	mlx_hook(game.s_mlx.window, ON_DESTROY, 0, on_destroy, &game);
	mlx_loop(game.s_mlx.mlx);
}

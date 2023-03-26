/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:57:36 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/26 20:32:41 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h> // for debugging

int	on_keydown(int keycode, t_game *game)
{
	if (keycode == KEY_ESCAPE)
		safely_terminate(game);
	else if (keycode == KEY_W)
	{
		game->player.position.x += game->player.direction.x * 0.1;
		game->player.position.y += game->player.direction.y * 0.1;

		// This may not cut it when we have ground and ceiling colors
		fake_fill_image(game->s_mlx.image, BLACK);
		fill_image(game->s_mlx.image, *game);
		mlx_put_image_to_window(game->s_mlx.mlx, game->s_mlx.window, game->s_mlx.image->image, 0, 0);
	}
	else if (keycode == KEY_S)
	{
		game->player.position.x -= game->player.direction.x * 0.1;
		game->player.position.y -= game->player.direction.y * 0.1;

		// This may not cut it when we have ground and ceiling colors
		fake_fill_image(game->s_mlx.image, BLACK);
		fill_image(game->s_mlx.image, *game);
		mlx_put_image_to_window(game->s_mlx.mlx, game->s_mlx.window, game->s_mlx.image->image, 0, 0);
	}
	return (0);
}

int	on_destroy(t_game *game)
{
	safely_terminate(game);
	return (0);
}

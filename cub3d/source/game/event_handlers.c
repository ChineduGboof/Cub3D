/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:57:36 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/29 23:07:06 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h> // for debugging

void	move_player(t_game *game, int movement_direction)
{
	if (movement_direction == NORTH)
	{
		game->player.position.x += game->player.direction.x * 0.1;
		game->player.position.y += game->player.direction.y * 0.1;
	}
	else if (movement_direction == SOUTH)
	{
		game->player.position.x -= game->player.direction.x * 0.1;
		game->player.position.y -= game->player.direction.y * 0.1;
	}
	else if (movement_direction == EAST)
	{
		game->player.position.x += game->player.direction.y * 0.1;
		game->player.position.y -= game->player.direction.x * 0.1;
	}
	else if (movement_direction == WEST)
	{
		game->player.position.x -= game->player.direction.y * 0.1;
		game->player.position.y += game->player.direction.x * 0.1;
	}
	paint_image(game->s_mlx.image, game->specifications.ceiling_color, 0, WINDOW_HEIGHT / 2);
	paint_image(game->s_mlx.image, game->specifications.floor_color, WINDOW_HEIGHT / 2, WINDOW_HEIGHT);
	fill_image(game->s_mlx.image, *game);
	mlx_put_image_to_window(game->s_mlx.mlx, game->s_mlx.window, game->s_mlx.image->image, 0, 0);
}

void	rotate_player(t_game *game, int rotation_direction)
{
	double rotation_speed;

	if (rotation_direction == RIGHT)
		rotation_speed = -0.1;
	else if (rotation_direction == LEFT)
		rotation_speed = 0.1;
	rotate_vector(&game->player.direction, rotation_speed);
	rotate_vector(&game->player.plane, rotation_speed);
	paint_image(game->s_mlx.image, game->specifications.ceiling_color, 0, WINDOW_HEIGHT / 2);
	paint_image(game->s_mlx.image, game->specifications.floor_color, WINDOW_HEIGHT / 2, WINDOW_HEIGHT);
	fill_image(game->s_mlx.image, *game);
	mlx_put_image_to_window(game->s_mlx.mlx, game->s_mlx.window, game->s_mlx.image->image, 0, 0);
}

int on_keydown(int keycode, t_game *game)
{
	if (keycode == KEY_ESCAPE)
		safely_terminate(game);
	else if (keycode == KEY_W)
		move_player(game, NORTH);
	else if (keycode == KEY_S)
		move_player(game, SOUTH);
	else if (keycode == KEY_D)
		move_player(game, EAST);
	else if (keycode == KEY_A)
		move_player(game, WEST);
	else if (keycode == KEY_LEFT)
		rotate_player(game, LEFT);
	else if (keycode == KEY_RIGHT)
		rotate_player(game, RIGHT);
	return (0);
}

int on_destroy(t_game *game)
{
	safely_terminate(game);
	return (0);
}

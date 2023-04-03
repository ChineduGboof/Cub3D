/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:20:46 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/03 19:50:09 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_vector	calculate_new_position(t_game *game, int movement_direction)
{
	t_vector	new_pos;

	if (movement_direction == NORTH)
	{
		new_pos.x = game->player.position.x + (-game->player.direction.x) * 0.1;
		new_pos.y = game->player.position.y + game->player.direction.y * 0.1;
	}
	else if (movement_direction == SOUTH)
	{
		new_pos.x = game->player.position.x - (-game->player.direction.x) * 0.1;
		new_pos.y = game->player.position.y - game->player.direction.y * 0.1;
	}
	else if (movement_direction == WEST)
	{
		new_pos.x = game->player.position.x + game->player.direction.y * 0.1;
		new_pos.y = game->player.position.y - (-game->player.direction.x) * 0.1;
	}
	else
	{
		new_pos.x = game->player.position.x - game->player.direction.y * 0.1;
		new_pos.y = game->player.position.y + (-game->player.direction.x) * 0.1;
	}
	return (new_pos);
}

bool	is_valid_position(t_game *game, double x, double y)
{
	int	new_x;
	int	new_y;

	new_x = (int)x;
	new_y = (int)y;
	if (new_y <= 0 || new_y >= (int)get_int_map_height(game->map))
		return (false);
	else if (new_x <= 0
		|| new_x >= (int)get_map_row_width(game->specifications.map[new_y]))
		return (false);
	return (game->map[new_y][new_x] == 0);
}

void	move_player(t_game *game, int movement_direction)
{
	t_vector	new_position;

	new_position = calculate_new_position(game, movement_direction);
	if (is_valid_position(game, new_position.x, new_position.y))
	{
		game->player.position = new_position;
		refresh_display(game);
	}
}

void	rotate_player(t_game *game, int rotation_direction)
{
	double	rotation_speed;

	if (rotation_direction == RIGHT)
		rotation_speed = -0.1;
	else
		rotation_speed = 0.1;
	rotate_vector(&game->player.direction, rotation_speed);
	rotate_vector(&game->player.plane, rotation_speed);
	paint_image(game->s_mlx.image,
		game->specifications.ceiling_color, 0, WINDOW_HEIGHT / 2);
	refresh_display(game);
}

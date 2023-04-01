/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:57:36 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 23:22:36 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h> // for debugging

int	on_keydown(int keycode, t_game *game)
{
	if (keycode == KEY_ESCAPE)
		safely_terminate(game, 0);
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

int	on_destroy(t_game *game)
{
	safely_terminate(game, 0);
	return (0);
}

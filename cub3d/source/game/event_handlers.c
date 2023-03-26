/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:57:36 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/26 19:48:11 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h> // for debugging

int	on_keydown(int keycode, t_game *game)
{
	if (keycode == KEY_ESCAPE)
		safely_terminate(game);
	return (0);
}

int	on_destroy(t_game *game)
{
	safely_terminate(game);
	return (0);
}

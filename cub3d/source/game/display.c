/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:54:30 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 18:08:18 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	refresh_display(t_game *game)
{
	paint_image(game->s_mlx.image, game->specifications.ceiling_color,
		0, WINDOW_HEIGHT / 2);
	paint_image(game->s_mlx.image, game->specifications.floor_color,
		WINDOW_HEIGHT / 2, WINDOW_HEIGHT);
	fill_image(game->s_mlx.image, *game);
	mlx_put_image_to_window(game->s_mlx.mlx, game->s_mlx.window,
		game->s_mlx.image->image, 0, 0);
}

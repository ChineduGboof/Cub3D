/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:56:25 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/23 15:04:05 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_game(void)
{
	void	*mlx;
	// void	*window;

	mlx = mlx_init();
	mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	mlx_loop(mlx);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:56:25 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/23 17:51:04 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "image/image.h"

void	run_game(t_specifications specifications)
{
	void	*mlx;
	void	*window;
	t_image	*image;

	mlx = mlx_init();
	image = create_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	if (!image || !window)
	{
		ft_putstr_fd("Error: failed to create window or image", STDERR_FILENO);
		return ;
	}
	mlx_put_image_to_window(mlx, window, image->image, 0, 0);
	mlx_loop(mlx);
	(void)specifications;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_termination.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:16:10 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/30 17:47:36 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "cub3d.h"

// We should make sure that we free all the memory
// we allocated before exiting the program.
void	safely_terminate(t_game *game)
{
	mlx_destroy_image(game->s_mlx.mlx, game->s_mlx.image->image);
	mlx_destroy_window(game->s_mlx.mlx, game->s_mlx.window);
	free(game->s_mlx.image);
	free(game->s_mlx.mlx);
	ft_free_2d_array((void ***)&(game->specifications.map), 0, false);
	ft_free_2d_array((void ***)&(game->map), 24, false); // temporary
	exit(0);
}

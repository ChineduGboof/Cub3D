/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_termination.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 18:16:10 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/02 04:15:15 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../cub3d.h"

void	free_textures(t_specifications *specifications)
{
	ft_cautious_free((void **)&specifications->north_texture);
	ft_cautious_free((void **)&specifications->south_texture);
	ft_cautious_free((void **)&specifications->west_texture);
	ft_cautious_free((void **)&specifications->east_texture);
}

void	release_mlx_resources(t_game *game)
{
	if (game->s_mlx.image)
		mlx_destroy_image(game->s_mlx.mlx, game->s_mlx.image->image);
	if (game->s_textures.north_wall)
		mlx_destroy_image(game->s_mlx.mlx, game->s_textures.north_wall->image);
	if (game->s_textures.south_wall)
		mlx_destroy_image(game->s_mlx.mlx, game->s_textures.south_wall->image);
	if (game->s_textures.west_wall)
		mlx_destroy_image(game->s_mlx.mlx, game->s_textures.west_wall->image);
	if (game->s_textures.east_wall)
		mlx_destroy_image(game->s_mlx.mlx, game->s_textures.east_wall->image);
	if (game->s_mlx.window)
		mlx_destroy_window(game->s_mlx.mlx, game->s_mlx.window);
}

// We should make sure that we free all the memory
// we allocated before exiting the program.
void	safely_terminate(t_game *game, int error_code)
{
	release_mlx_resources(game);
	free(game->s_mlx.image);
	free(game->s_textures.north_wall);
	free(game->s_textures.south_wall);
	free(game->s_textures.west_wall);
	free(game->s_textures.east_wall);
	free(game->s_mlx.mlx);
	ft_free_2d_array((void ***)&(game->map), 0, true);
	ft_free_2d_array((void ***)(&(game->specifications.map)), 0, true);
	free_textures(&(game->specifications));
	exit(error_code);
}

void	terminate_with_message(t_game *game, char *message, int error_code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	safely_terminate(game, error_code);
}

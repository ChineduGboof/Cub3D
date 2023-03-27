/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:25:30 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/27 18:18:22 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h> // for debug

bool	load_textures(void *mlx, struct s_textures *s_textures, t_specifications specifications)
{
	s_textures->east_wall = import_image(mlx, specifications.east_texture);
	s_textures->west_wall = import_image(mlx, specifications.west_texture);
	s_textures->south_wall = import_image(mlx, specifications.south_texture);
	s_textures->north_wall = import_image(mlx, specifications.north_texture);
	if (s_textures->east_wall && s_textures->west_wall
		&& s_textures->south_wall && s_textures->north_wall)
		return (true);
	else
		return (false);
}
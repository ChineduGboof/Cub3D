/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:25:30 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/03 13:41:28 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

bool	load_textures(void *mlx, struct s_textures *s_textures,
			t_specifications specifications)
{
	s_textures->west_wall = import_image(mlx, specifications.east_texture);
	s_textures->east_wall = import_image(mlx, specifications.west_texture);
	s_textures->north_wall = import_image(mlx, specifications.south_texture);
	s_textures->south_wall = import_image(mlx, specifications.north_texture);
	if (s_textures->east_wall && s_textures->west_wall
		&& s_textures->south_wall && s_textures->north_wall)
		return (true);
	else
		return (false);
}

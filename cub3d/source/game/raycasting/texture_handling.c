/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handling.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:47:40 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/03 16:44:17 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"
#include "raycasting_local.h"

t_image	*choose_texture(t_game game, int wall_hit_direction)
{
	if (wall_hit_direction == NORTH)
		return (game.s_textures.north_wall);
	else if (wall_hit_direction == SOUTH)
		return (game.s_textures.south_wall);
	else if (wall_hit_direction == EAST)
		return (game.s_textures.east_wall);
	else if (wall_hit_direction == WEST)
		return (game.s_textures.west_wall);
	return (NULL);
}

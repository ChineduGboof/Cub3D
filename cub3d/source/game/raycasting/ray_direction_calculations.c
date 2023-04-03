/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_direction_calculations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:57:37 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/03 19:44:03 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

t_vector	calculate_ray_direction(t_player player, double offset_from_center)
{
	t_vector	ray_direction;

	ray_direction.x = -(player.direction.x
		+ (player.plane.x * offset_from_center));
	ray_direction.y = player.direction.y
		+ (player.plane.y * offset_from_center);
	return (ray_direction);
}

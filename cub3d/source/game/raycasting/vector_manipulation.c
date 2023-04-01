/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_manipulation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 21:49:36 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/30 17:42:57 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

// for turning around
void	rotate_vector(t_vector *vector, double angle)
{
	t_vector	old_vector;

	old_vector = *vector;
	vector->x = old_vector.x * cos(angle) - old_vector.y * sin(angle);
	vector->y = old_vector.x * sin(angle) + old_vector.y * cos(angle);
}

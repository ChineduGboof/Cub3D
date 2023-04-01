/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_map_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:54:11 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 23:23:02 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

size_t	get_int_map_height(int **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

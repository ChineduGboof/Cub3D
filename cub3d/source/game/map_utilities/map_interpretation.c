/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_interpretation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:57:58 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/03 19:52:33 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

t_vector	get_player_position(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				return ((t_vector){j + 0.5, i + 0.5});
			j++;
		}
		i++;
	}
	return ((t_vector){0, 0});
}

t_vector	get_player_direction(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return ((t_vector){0, -1});
			else if (map[i][j] == 'S')
				return ((t_vector){0, 1});
			else if (map[i][j] == 'E')
				return ((t_vector){-1, 0});
			else if (map[i][j] == 'W')
				return ((t_vector){1, 0});
			j++;
		}
		i++;
	}
	return ((t_vector){0, 0});
}

t_vector	determine_plane(char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				return ((t_vector){-0.66, 0});
			else if (map[i][j] == 'S')
				return ((t_vector){0.66, 0});
			else if (map[i][j] == 'E')
				return ((t_vector){0, 0.66});
			else if (map[i][j] == 'W')
				return ((t_vector){0, -0.66});
			j++;
		}
		i++;
	}
	return ((t_vector){0, 0});
}

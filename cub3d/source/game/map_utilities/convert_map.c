/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:55:40 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 22:00:31 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

size_t	get_map_height(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

size_t	get_map_row_width(char *row)
{
	size_t	i;

	i = 0;
	while (row[i])
		i++;
	return (i);
}

int	**convert_map(char **map)
{
	int		**result;
	int		i;
	int		j;

	result = ft_calloc(get_map_height(map) + 1, sizeof(int *));
	i = 0;
	while (map[i])
	{
		result[i] = ft_calloc(get_map_row_width(map[i]), sizeof(int));
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				result[i][j] = 0;
			else if (ft_isspace(map[i][j]))
				result[i][j] = '1';
			else
				result[i][j] = map[i][j] - '0';
			j++;
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:02:07 by gboof             #+#    #+#             */
/*   Updated: 2023/04/02 00:27:12 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

enum {
	N,
	E,
	S,
	W
};

void	determine_directions(int direction, int *di, int *dj)
{
	if (direction == N)
	{
		*di = 0;
		*dj = 1;
	}
	else if (direction == S)
	{
		*di = 0;
		*dj = -1;
	}
	else if (direction == E)
	{
		*di = 1;
		*dj = 0;
	}
	else
	{
		*di = -1;
		*dj = 0;
	}
}

bool	has_wall_in_direction(int i, int j, char **map, int direction)
{
	int	x;
	int	y;
	int	dj;
	int	di;

	determine_directions(direction, &di, &dj);
	x = j + dj;
	y = i + di;
	while (y >= 0 && map[y] && x >= 0 && map[y][x])
	{
		if (map[y][x] == '1')
			return (true);
		x += dj;
		y += di;
	}
	return (false);
}

/*	
	N = 0, 1
	S = 0, -1
	E =  1, 0
	W = -1, 0
*/
bool	is_walled(int i, int j, char **map)
{
	bool	left_vertical;
	bool	right_vertical;
	bool	up_horizontal;
	bool	down_horizontal;

	left_vertical = has_wall_in_direction(i, j, map, S);
	right_vertical = has_wall_in_direction(i, j, map, N);
	up_horizontal = has_wall_in_direction(i, j, map, W);
	down_horizontal = has_wall_in_direction(i, j, map, E);
	return (left_vertical && right_vertical
		&& up_horizontal && down_horizontal);
}

bool	is_valid_fence(char *row)
{
	int	i;

	i = 0;
	while (row[i] != '\0')
	{
		if (row[i] != '1' && row[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

char	*get_first_row(char **map)
{
	char	*first_row;

	first_row = map[0];
	if (!first_row)
		return (NULL);
	if (is_valid_fence(first_row))
		return (first_row);
	return (NULL);
}

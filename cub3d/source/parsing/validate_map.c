/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:02:07 by gboof             #+#    #+#             */
/*   Updated: 2023/04/01 23:54:35 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	has_wall_in_direction(int i, int j, char **map, int di, int dj)
{
	int	x;
	int	y;

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

bool	is_walled(int i, int j, char **map)
{
	bool	left_vertical;
	bool	right_vertical;
	bool	up_horizontal;
	bool	down_horizontal;

	left_vertical = has_wall_in_direction(i, j, map, 0, -1);
	right_vertical = has_wall_in_direction(i, j, map, 0, 1);
	up_horizontal = has_wall_in_direction(i, j, map, -1, 0);
	down_horizontal = has_wall_in_direction(i, j, map, 1, 0);
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

char	*get_last_row(char **map)
{
	char	*last_row;
	int		num_rows;

	last_row = map[0];
	num_rows = 0;
	while (map[num_rows] != NULL)
	{
		last_row = map[num_rows];
		num_rows++;
	}
	if (is_valid_fence(last_row))
		return (last_row);
	return (NULL);
}

char	*get_next_row(char ***map_ptr, char *last_row)
{
	char	*current_row;

	current_row = **map_ptr;
	if (current_row != NULL && current_row != last_row)
	{
		if (is_valid_fence(current_row) && current_row[0] == '1' && current_row[ft_strlen(current_row)-1] == '1')
		{
			*map_ptr += 1;
			return (current_row);
		}
	}
	return (NULL);
}

bool is_fenced(char **map)
{
	char	*first_row;
	char	*last_row;
	char	**map_ptr;
	char	*current_row;

	first_row = get_first_row(map);
	last_row = get_last_row(map);
	if (!first_row || !last_row)
		return false;
	map_ptr = map + 1;
	current_row = get_next_row(&map_ptr, last_row);
	while (current_row != NULL)
	{
		current_row = get_next_row(&map_ptr, last_row);
	}
	return (true);
}


void	check_map_errors(char **map)
{
	int		player_count;
	size_t	i;
	size_t	j;

	player_count  = 0;
	i = -1;
	j = 0;
	if (!is_fenced(map))
		ft_exit_msg("Map is not fenced.");
	while(map[++i])
	{
		j = 0;
		while(map[i][j] != '\0')
		{
			if(map[i][j] != '0' || map[i][j] != '1' || map[i][j] != ' ' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				if((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W'))
				{
					player_count++;
					if (player_count > 1 || i == 0 || j == 0 || j == ft_strlen(map[i]) - 1 || map[i+1] == NULL)
							ft_exit_msg("Duplicate or muliple players in the map.");
				}
				if (map[i][j] == '0')
				{
					if(!is_walled(i, j, map))
						ft_exit_msg("Map is not walled.");
				}
				j++; 
			}
			else
				ft_exit_msg("Map is not valid.");
		}
	}
	if(player_count == 0)
		ft_exit_msg("NO PLAYER.");
}

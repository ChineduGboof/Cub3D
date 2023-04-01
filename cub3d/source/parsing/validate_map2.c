/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:25:55 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/02 01:21:43 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		if (is_valid_fence(current_row) && current_row[0] == '1'
			&& current_row[ft_strlen(current_row) - 1] == '1')
		{
			*map_ptr += 1;
			return (current_row);
		}
	}
	return (NULL);
}

bool	is_fenced(char **map)
{
	char	*first_row;
	char	*last_row;
	char	**map_ptr;
	char	*current_row;

	first_row = get_first_row(map);
	last_row = get_last_row(map);
	if (!first_row || !last_row)
		return (false);
	map_ptr = map + 1;
	current_row = get_next_row(&map_ptr, last_row);
	while (current_row != NULL)
	{
		current_row = get_next_row(&map_ptr, last_row);
	}
	return (true);
}

void	check_row(char **map, size_t *i, size_t *j, int *player_count)
{
	if (map[*i][*j] != '0' || map[*i][*j] != '1' || map[*i][*j] != ' '
		|| map[*i][*j] == 'N' || map[*i][*j] == 'S' || map[*i][*j] == 'E'
			|| map[*i][*j] == 'W')
	{
		if ((map[*i][*j] == 'N' || map[*i][*j] == 'S' || map[*i][*j] == 'E'
			|| map[*i][*j] == 'W'))
		{
			(*player_count)++;
			if (*player_count > 1 || *i == 0 || *j == 0
				|| *j == ft_strlen(map[*i]) - 1 || map[(*i) + 1] == NULL)
				free_map_assured(map,
					"Duplicate or muliple players in the map.", 1);
		}
		if (map[*i][*j] == '0')
		{
			if (!is_walled(*i, *j, map))
				free_map_assured(map, "Map is not walled.", 1);
		}
		(*j)++;
	}
	else
		free_map_assured(map, "Map is not valid.", 1);
}

void	check_map_errors(char **map)
{
	int		player_count;
	size_t	i;
	size_t	j;

	player_count = 0;
	i = -1;
	j = 0;
	if (!is_fenced(map))
		free_map_assured(map, "Map is not fenced.", 1);
	while (map[++i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			check_row(map, &i, &j, &player_count);
		}
	}
	if (player_count == 0)
		free_map_assured(map, "No player.", 1);
}

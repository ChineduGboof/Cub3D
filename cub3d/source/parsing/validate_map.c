/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:02:07 by gboof             #+#    #+#             */
/*   Updated: 2023/04/01 12:12:41 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool is_walled(int i, int j, char **map)
{
	bool left_vertical = false;
	bool right_vertical = false;
	bool left_horizontal = false;
	bool right_horizontal = false;
	
	// Check for walls on the left and right of the 0
	int x = j - 1;
	while (x >= 0) {
		if (map[i][x] == '1') {
			left_horizontal = true;
			break;
		}
		x--;
	}
	x = j + 1;
	while (map[i][x]) {
		if (map[i][x] == '1') {
			right_horizontal = true;
			break;
		}
		x++;
	}
	// Check for walls above and below the 0
	int y = i - 1;
	while (y >= 0) {
		if (map[y][j] == '1') {
			left_vertical = true;
			break;
		}
		y--;
	}
	y = i + 1;
	while (map[y]) {
		if (map[y][j] == '1') {
			right_vertical = true;
			break;
		}
		y++;
	}
	return left_vertical && right_vertical && left_horizontal && right_horizontal;
}

bool is_fenced(char **map) {
	// Check the first row
	char *first_row = map[0];
	if (!first_row) {
		return false;
	}
	int i = 0;
	while (first_row[i] != '\0') {
		if (first_row[i] != '1' && first_row[i] != ' ') {
			return false;
		}
		i++;
	}
	
	// Check the last row
	char *last_row = map[0];
	int num_rows = 0;
	while (map[num_rows] != NULL) {
		last_row = map[num_rows];
		num_rows++;
	}
	i = 0;
	while (last_row[i] != '\0') {
		if (last_row[i] != '1' && last_row[i] != ' ') {
			return false;
		}
		i++;
	}
	
	// Check the other rows
	char *current_row = map[1];
	while (current_row != NULL && current_row != last_row) {
		if (current_row[0] != '1' && current_row[0] != ' ') {
			return false;
		}
		int len = ft_strlen(current_row);
		if (current_row[len-1] != '1') {
			return false;
		}
		current_row = *(++map);
	}
	
	return true;
}


void check_map_errors(char **map)
{
	int	player_count;
	size_t	i;
	size_t	j;

	player_count  = 0;
	i = 0;
	j = 0;
	if (!is_fenced(map))
		ft_exit_msg("Map is not fenced.");
	while(map[i])
	{
		j = 0;
		while(map[i][j] != '\0')
		{
			// checks if the only valid characters are in the map
			if(map[i][j] != '0' || map[i][j] != '1' || map[i][j] != ' ' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
			{
				//checks for duplicate players
				if((map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W'))
				{
					player_count++;
					if (player_count > 1 || i == 0 || j == 0 || j == ft_strlen(map[i]) - 1 || map[i+1] == NULL)
							ft_exit_msg("Duplicate or muliple players in the map.");
				}
				
				//3. check each zero if it has a one on the left or right
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
		i++;
	}
	if(player_count == 0)
		ft_exit_msg("NO PLAYER.");
	
}

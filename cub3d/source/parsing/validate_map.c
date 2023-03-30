/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:02:07 by gboof             #+#    #+#             */
/*   Updated: 2023/03/30 20:09:28 by cegbulef         ###   ########.fr       */
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
    bool first_row_ok = true;
    bool last_row_ok = true;
    
    // Check first row
    int j = 0;
    while (map[0][j] != '\0') {
        if (map[0][j] != '1' && map[0][j] != ' ') {
            first_row_ok = false;
            break;
        }
        j++;
    }
    
    // Check last row
    j = 0;
    while (map[1][j] != '\0') {
        if (map[1][j] != '1' && map[1][j] != ' ') {
            last_row_ok = false;
            break;
        }
        j++;
    }
    
    // Check other rows
    int i = 2;
    while (map[i] != NULL) {
        j = 0;
        while (map[i][j] != '\0') {
            if (j == 0) {
                if (map[i][j] != '1' && map[i][j] != ' ') {
                    return false;
                }
            }
            else if (map[i][j+1] == '\0') {
                if (map[i][j] != '1') {
                    return false;
                }
            }
            j++;
        }
        i++;
    }
    
    return first_row_ok && last_row_ok;
}

void check_map_errors(char **map)
{
	int	player_count;
	size_t	i;
	size_t	j;
	// int map_len;
	
	// map_len = ft_arrlen(map) - 1;
	player_count  = 0;
	i = 0;
	j = 0;
	if (!is_fenced(map))
	{
		printf("Error: Map is not fenced.\n");
		exit(0);
	}
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
					{
							printf("Error: Duplicate or muliple players in the map\n");
							exit(0);
					}
				}
				//start here
				
				//3. check each zero if it has a one on the left or right
				if (map[i][j] == '0')
				{
					if(!is_walled(i, j, map))
					{
						printf("Error: Map is not walled.\n");
						exit(0);
					}
				}
				j++; 
			}
			else
				printf("Error: Map is not valid.\n");
		}
		i++;
	}
	if(player_count == 0)
		printf("Error: NO PLAYER.\n");
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:02:07 by gboof             #+#    #+#             */
/*   Updated: 2023/03/30 17:30:40 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// "Error: Map is not surrounded by walls.\n"
// "Error: Map is not closed.\n"
// "Error: Player not found in the map.\n"

/*
	flag[0] => right
	flag[1] => left
	flag[2] => top
	flag[3] => bottom
*/
// bool	is_walled(int i, int j, char **map)
// {
// 	bool flag[4];
// 	int len;

// 	ft_bzero(flag, sizeof(bool) * 4);
// 	len = ft_strlen(map[i]) - 1;
// 	while(map[i])
// 	{
// 		while(map[i][j])
// 		{
// 			j++;
// 		}
// 		i++;
// 	}
	
// }
bool is_walled(int i, int j, char **map) {
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

void check_map_errors(char **map)
{
	int	player_count;
	size_t	i;
	size_t	j;
	int map_len;
	

	map_len = ft_arrlen(map) - 1;
	player_count  = 0;
	i = 0;
	j = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
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
				//1. loop thru 1st and last row and check if its only 1s or spaces
				if ((map[0][j] && map[0][j] != '1' && map[0][j] != ' '))
				{
					printf("Error: Map is not closed1.\n");
					exit(0);
				}
				if (map[map_len][j] && (map[map_len][j] != '1' && map[map_len][j] != ' '))
				{
					printf("Error: Map is not closed1.\n");
					exit(0);
				}
				//2. check the first and last of every string. space can begin but not end
				if ((map[i][0] != '1' && map[i][0] != ' ') || map[i][ft_strlen(map[i]) - 1] != '1')
				{
					printf("Error: Map is not closed2.\n");
					exit(0);
				}
				//3. check each zero if it has a one on the left or right
				//set each of the flags to true
				// if all the flags are true good. if any is false then bad
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

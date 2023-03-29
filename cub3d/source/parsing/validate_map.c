/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:02:07 by gboof             #+#    #+#             */
/*   Updated: 2023/03/29 23:06:43 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     is_wall(char *str)
{
    for (size_t i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] != '1' && str[i] != ' ')
            return (0);
    }
    return (1);
}

int     is_valid_player(char *str)
{
    static bool is_player_found = false;

    if (ft_strchr(str, 'N') != NULL || ft_strchr(str, 'S') != NULL ||
        ft_strchr(str, 'E') != NULL || ft_strchr(str, 'W') != NULL)
    {
        if (is_player_found)
        {
            printf("Error: Duplicate players in the map.\n");
            exit(EXIT_FAILURE);
        }
        is_player_found = true;
    }
    return (0);
}

int     check_all_sides(char **strs, int j)
{
    if (ft_isspace(strs[-1][j - 1]) || !strs[-1][j - 1])
        return (0);
    if (ft_isspace(strs[-1][j]) || !strs[-1][j])
        return (0);
    if (ft_isspace(strs[-1][j + 1]) || !strs[-1][j + 1])
        return (0);
    if (ft_isspace(strs[0][j - 1]) || !strs[0][j - 1])
        return (0);
    if (ft_isspace(strs[0][j + 1]) || !strs[0][j + 1])
        return (0);
    if (ft_isspace(strs[1][j - 1]) || !strs[1][j - 1])
        return (0);
    if (ft_isspace(strs[1][j]) || !strs[1][j])
        return (0);
    if (ft_isspace(strs[1][j + 1]) || !strs[1][j + 1])
        return (0);
    return (1);
}

void    exit_error(char *str, int err)
{
    printf("%s\n", str);
    exit(err);
}

void check_map_errors(char **map)
{
    size_t i;
    size_t j;
    int err_code;
    int is_closed_map;
    bool is_wall_valid;
    bool is_player_found;
    char **tmp;

    i = 0;
    is_closed_map = 1;
    is_wall_valid = false;
    is_player_found = false;
    tmp = (char **) malloc(sizeof(char *) * 3);
    while (map[i] != NULL)
    {
        j = 0;
        if (is_wall(map[i]))
        {
            if (i == 0 || i == (ft_strlen(map[i]) - 1))
            {
                is_wall_valid = true;
            }
        }
        while (map[i][j] != '\0')
        {
            if (map[i][j] != '1' && map[i][j] != ' ')
            {
                if (i == 0 || j == 0 || map[i + 1] == NULL || map[i][j + 1] == '\0')
                {
                    exit_error("Error: Map is not surrounded by walls.\n", ERR_EXIT);
                }
                if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
                {
                    if (is_player_found)
                    {
                        exit_error("Error: Duplicate players in the map.\n", ERR_EXIT);
                    }
                    is_player_found = true;
                }
                else if (map[i][j] != '1' && map[i][j] != ' ' && !is_closed_map)
                {
                    exit_error("Error: Map is not closed.\n", ERR_EXIT);
                }
                else if (map[i][j] != '1' && map[i][j] != ' ')
                {
                    tmp[0] = map[i - 1] + j - 1;
                    tmp[1] = map[i] + j - 1;
                    tmp[2] = map[i + 1] + j - 1;
                    if (!check_all_sides(tmp, 1))
                    {
                        exit_error("Error: Map is not valid.\n", ERR_EXIT);
                    }
                }
            }
            j++;
        }
        i++;
    }
    if (!is_wall_valid)
    {
        exit_error("Error: Map is not valid.\n", ERR_EXIT);
    }
    if (!is_player_found)
    {
        exit_error("Error: Player not found in the map.\n", ERR_EXIT);
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:53:52 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/01 21:01:24 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(t_specifications *specifications, int status)
{
    if (specifications->map != NULL)
    {
        ft_free_2d_array((void ***)&specifications->map, -1, true);
        specifications->map = NULL;
    }
    exit(status);
}

int	open_map(char *argument)
{
	int	fd;

	fd = open(argument, O_RDONLY);
	if (fd == -1)
	{
		ft_exit_msg("Could not open map file");
	}
	return (fd);
}

void parse_map(const char *map_file_path, t_specifications *specifications)
{
    int     fd;
    int     res;
    int		index;
    char    *line;
    int     map_size;
    int     map_index;

    map_size = 4096;
    map_index = 0;
    line = NULL;
    fd = open_map(map_file_path);
    specifications->map = (char **)ft_calloc(map_size, sizeof(char *));
    if (specifications->map == NULL)
        free_map(specifications, EXIT_FAILURE);
    while (1)
    {
        res = get_line(fd, &line);
        if (res <= 0)
			break;
        if (*line == '\0')
            continue;
        index = 0;
		while (ft_isspace(line[index]))
			index++;
        if (ft_strnstr(line + index, NO, 3) || ft_strnstr(line + index, SO, 3)
                || ft_strnstr(line + index, WE, 3) || ft_strnstr(line + index, EA, 3)
                || ft_strnstr(line + index, F, 2) || ft_strnstr(line + index, C, 2))
        {
            ft_cautious_free((void **)&line);
            continue;
        }
        else
        {
            char *new_line = ft_strdup_replace_tabs_with_space(line);
            if (new_line == NULL)
                free_map(specifications, EXIT_FAILURE);
            if (map_index >= map_size)
            {
                specifications->map = (char **)ft_realloc(specifications->map,
                                                         map_size * sizeof(char *),
                                                         (map_size + 4096) * sizeof(char *));
                if (specifications->map == NULL)
                    free_map(specifications, EXIT_FAILURE);
                map_size += 4096;
            }
            specifications->map[map_index] = new_line;
            map_index++;
        }
    }
    close(fd);
    check_map_errors(specifications->map);
}

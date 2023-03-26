/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:50:53 by gboof             #+#    #+#             */
/*   Updated: 2023/03/26 05:31:52 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_map_line(char *line)
{
	if (ft_strchr(line, ' '))
		error_exit("Error: Invalid map");
	if (ft_strlen(line) == 0)
		return ;
	if (ft_countwords(line, ' ') > 3)
		error_exit("Error: Too many arguments");
}

static void	check_first_map_line(char *line, int *map_started)
{
	if (ft_strncmp(line, "1", 1) != 0 && ft_strncmp(line, " ", 1) != 0)
		error_exit("Error: Invalid map");
	*map_started = 1;
}

static void	check_identifier(char *line, char **ids)
{
	int	i;

	i = 0;
	while (ids[i])
	{
		if (ft_strncmp(ids[i], line, ft_strlen(ids[i])) == 0)
		{
			if (ft_countwords(line, ' ') > 2)
				error_exit("Error: Too many arguments");
			break ;
		}
		i++;
	}
	if (!ids[i])
		error_exit("Error: Invalid identifier");
}

void	check_identifiers(int fd)
{
	char	**ids;
	// int		i;
	int		map_started;
	char	*line;

	// i = 0;
	map_started = 0;
	ids = ft_split(VALID_IDS, ' ');
	while (get_next_line(fd))
	{
		line = get_next_line(fd);
		if (ft_isprint(line[0]))
		{
			if (map_started)
				check_map_line(line);
			else
				check_first_map_line(line, &map_started);
			check_identifier(line, ids);
		}
		free(line);
	}
	free(ids);
}

void	check_range(char **rgb)
{
	int		i;
	long	val;

	i = -1;
	while (++i < 3)
	{
		if (!ft_isnumeric(*rgb[i]))
		{
			ft_putstr_fd("Error: Non-numeric color value\n", 2);
			exit(EXIT_FAILURE);
		}
		val = ft_atol(rgb[i]);
		if (val < 0 || val > 255 || ft_strlen(rgb[i]) > 3)
		{
			ft_putstr_fd("Error: Invalid color range\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

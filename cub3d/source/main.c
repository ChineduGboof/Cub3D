/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:15:33 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/03 15:04:45 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_line(char *line)
{
	size_t	index;
	bool	result;

	index = 0;
	result = false;
	if (!line || line[0] == '\0' || line[0] == '\n')
		return (false);
	while (line[index] && line[index] != '\n')
	{
		if (!(line[index] == '0' || line[index] == '1' || line[index] == 'E'
				|| line[index] == 'N' || line[index] == 'S'
				|| line[index] == 'W' || line[index] == 'N'
				|| line[index] == ' ' || line[index] == '\t'))
			return (false);
		if (line[index] == '0' || line[index] == '1' || line[index] == 'E'
			|| line[index] == 'N' || line[index] == 'S' || line[index] == 'W')
			result = true;
		index++;
	}
	return (result);
}

bool	wrong_placement(char *filename)
{
	char	*line;
	bool	map_started;
	int		fd;

	map_started = false;
	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_map_line(line))
			map_started = true;
		if (map_started && !is_map_line(line))
		{
			close(fd);
			return (true);
		}
		free(line);
	}
	close(fd);
	return (false);
}

int	main(int argc, char **argv)
{
	t_specifications	specifications;

	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	validate_argument(argv[1]);
	if (is_empty_file(argv[1]))
	{
		ft_putstr_fd("Error: map is empty\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (wrong_placement(argv[1]))
	{
		ft_putstr_fd("Error: wrong placement in map\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	parsing(argv[1], &specifications);
	run_game(specifications);
	return (0);
}

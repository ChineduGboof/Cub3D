/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:15:33 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/02 21:35:40 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_map_line(char *line)
{
	size_t index;
	bool	result;

	index = 0;
	result = false;
	if (!line || line[0] == '\0')
		return (false);
	while (line[index])
	{
		if (!(line[index] == '0' || line[index] == '1' || line[index] =='E'  || line[index] == 'N' || line[index] == 'S' || line[index] == 'W' || ft_isspace(line[index])))
			return (false);
		if (line[index] == '0' || line[index] == '1' || line[index] == 'E'  || line[index] == 'N' || line[index] == 'S' || line[index] == 'W')
			result = true;
		index++;
	}
	return (result);
}

bool wrong_placement(char *filename)
{
	char *line;
	bool map_started = false;
	int fd;

	fd = open(filename, O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		if (is_map_line(line))
			map_started = true;
		size_t index = 0;
		while (line[index])
		{
			if (map_started && !(line[index] == '0' || line[index] == '1' || line[index] == 'E'  || line[index] == 'N' || line[index] == 'S' || line[index] == 'W' || ft_isspace(line[index]) ))
			{
				close(fd);
				return (true);
			}
			index++;
		}
		free(line);
	}

	// Check if any of the required elements are missing
	close(fd);
	return false;
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

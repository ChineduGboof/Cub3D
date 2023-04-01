/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:15:33 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 12:09:34 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_empty_file(char *argument)
{
	int	fd;
	char	*line;
	
	fd = open(argument, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: could not open file", STDERR_FILENO);
		return (true);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (true);
	}
	close(fd);
	return (false);
}

bool	has_missing_specification(char *argument)
{
	int	fd;
	int	i;
	int	j;
	char	*line;
	char	*specifications[6] = {NO, SO, WE, EA, F, C};
	
	fd = open(argument, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: could not open file", STDERR_FILENO);
		return (true);
	}
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (get_line(fd, &line) > 0)
		{
			if (ft_strncmp(line, specifications[i], ft_strlen(specifications[i])) == 0)
			{
				j = 1;
				break ;
			}
		}
		if (j == 0)
		{
			close(fd);
			return (true);
		}
		i++;
	}
	while (get_line(fd, &line) > 0)
	{
		if (ft_strncmp(line, "1", 1) == 0)
		{
			close(fd);
			return (false);
		}
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
	if (is_empty_file(argv[1]) || has_missing_specification(argv[1]))
	{
		ft_putstr_fd("Error: map has missing specification\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	parsing(argv[1], &specifications);
	

	// prints the colors
	printf("Floor color: R:%d, G:%d, B:%d\n", \
		specifications.floor_color.red, \
		specifications.floor_color.green, \
		specifications.floor_color.blue);
	printf("Ceiling color: R:%d, G:%d, B:%d\n", \
		specifications.ceiling_color.red, \
		specifications.ceiling_color.green, \
		specifications.ceiling_color.blue);

	// init_struct(&specifications);
	// run_game(specifications);
	return (0);
}

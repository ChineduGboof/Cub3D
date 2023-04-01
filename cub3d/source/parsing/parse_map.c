/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:53:52 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/02 00:31:10 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

enum {
	fd,
	res,
	index,
	map_size,
	map_index
};

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

bool	find_identifier(char *line, int index)
{
	if (ft_strnstr(line + index, NO, 3) || ft_strnstr(line + index, SO, 3)
		|| ft_strnstr(line + index, WE, 3) || ft_strnstr(line + index, EA, 3)
		|| ft_strnstr(line + index, F, 2) || ft_strnstr(line + index, C, 2))
		return (true);
	return (false);
}

int	init_map(int *map_size, int *map_index, char *map_file_path,
			t_specifications *specifications)
{
	int	fd;

	*map_size = 4096;
	*map_index = 0;
	fd = open_map(map_file_path);
	specifications->map = (char **)ft_calloc(*map_size, sizeof(char *));
	if (specifications->map == NULL)
		free_map(specifications, EXIT_FAILURE);
	return (fd);
}

void	parse_line(char *line, t_specifications *specifications, int arr[])
{
	arr[index] = 0;
	while (ft_isspace(line[arr[index]]))
		arr[index]++;
	if (find_identifier(line, arr[index]))
	{
		ft_cautious_free((void **)&line);
		return ;
	}
	expand_map(line, specifications, arr[map_index], &arr[map_size]);
	arr[map_index]++;
}

void	parse_map(char *map_file_path, t_specifications *specifications)
{
	int		arr[5];
	char	*line;

	line = NULL;
	arr[fd] = init_map(&arr[map_size], &arr[map_index],
			map_file_path, specifications);
	while (1)
	{
		arr[res] = get_line(arr[fd], &line);
		if (arr[res] <= 0)
			break ;
		if (*line == '\0')
			continue ;
		parse_line(line, specifications, arr);
	}
	close(arr[fd]);
	check_map_errors(specifications->map);
}

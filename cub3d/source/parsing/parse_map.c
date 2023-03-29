/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:53:52 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/29 21:42:50 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(t_specifications *specifications, int status)
{
	if (specifications->map)
		ft_free_2d_array((void ***)&specifications->map, -1, true);
	exit(status);
}

void	parse_map(const char *map_file_path, t_specifications *specifications)
{
	int     fd;
	int     res;
	char    *line;
	int     map_size = 4096; // initial size of specifications->map array
	int     map_index = 0; // current index to insert line in specifications->map

	line = NULL;
	fd = open(map_file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: could not open map file");
		exit(EXIT_FAILURE);
	}

	// allocate initial specifications->map array
	specifications->map = (char **)malloc(sizeof(char *) * map_size);
	if (specifications->map == NULL)
		free_map(specifications, EXIT_FAILURE);

	while ((res = get_line(fd, &line)) > 0)
	{
		if (*line == '\0')
			continue;
		else if (ft_strnstr(line, NO, 3) == line ||
					ft_strnstr(line, SO, 3) == line ||
					ft_strnstr(line, WE, 3) == line ||
					ft_strnstr(line, EA, 3) == line ||
					ft_strnstr(line, F, 2) == line ||
					ft_strnstr(line, C, 2) == line)
		{
			ft_cautious_free((void **)&line);
			continue;
		}
		else
		{
			// expand specifications->map if necessary
			if (map_index >= map_size) {
				specifications->map = (char **)ft_realloc(specifications->map,
					map_size * sizeof(char *),
					(map_size + 4096) * sizeof(char *));
				if (specifications->map == NULL)
					free_map(specifications, EXIT_FAILURE);
				map_size += 4096;
			}

			// replace tabs with 4 spaces
			char *p = line;
			while (*p != '\0') 
			{
				if (*p == '\t') 
				{
					*p = ' ';
					for (int i = 0; i < 3; i++) 
					{
						p++;
						*p = ' ';
					}
				}
				p++;
			}
			// duplicate line into specifications->map
			specifications->map[map_index] = ft_strdup(line);
			if (specifications->map[map_index] == NULL)
				free_map(specifications, EXIT_FAILURE);
			map_index++;
		}
	}

	if (res == -1)
		free_map(specifications, EXIT_FAILURE);
	close(fd);

	// print content of map
	int k = 0;
	while (specifications->map[k])
	{
		printf("%s\n", specifications->map[k]);
		k++;
	}
	// free_map(specifications, EXIT_SUCCESS);
}


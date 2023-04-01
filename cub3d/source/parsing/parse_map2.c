/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:57:57 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/02 01:10:51 by oaydemir         ###   ########.fr       */
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

void	free_map_assured(char **map, char *message, int status)
{
	ft_free_2d_array((void ***)&map, -1, true);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	exit(status);
}

void	expand_map(char *line, t_specifications *specifications,
		int map_index, int *map_size)
{
	char	*new_line;

	new_line = ft_strdup_replace_tabs_with_space(line);
	ft_cautious_free((void **)&line);
	if (new_line == NULL)
		free_map(specifications, EXIT_FAILURE);
	if (map_index >= *map_size)
	{
		specifications->map = (char **)ft_realloc(specifications->map,
				*map_size * sizeof(char *),
				(*map_size + 4096) * sizeof(char *));
		if (specifications->map == NULL)
			free_map(specifications, EXIT_FAILURE);
		*map_size += 4096;
	}
	specifications->map[map_index] = new_line;
}

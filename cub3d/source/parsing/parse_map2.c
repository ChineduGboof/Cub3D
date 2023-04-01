/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:57:57 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/01 23:05:50 by cegbulef         ###   ########.fr       */
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

void	expand_map(char *line, t_specifications *specifications,
		int map_index, int *map_size)
{
	char	*new_line;

	new_line = ft_strdup_replace_tabs_with_space(line);
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

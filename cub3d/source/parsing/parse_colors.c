/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:52:28 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/29 19:46:14 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game/image/image.h"

void	ft_parse_color(char *line, t_color *color)
{
	char	**colors;
	char	*trimmed;
	int		i;

	i = -1;
	colors = ft_split(line + 2, ',');
	if (!colors || ft_arrlen(colors) != 3)
		ft_exit_error("Wrong number of color values");
	while (colors[++i])
	{
		trimmed = ft_strtrim(colors[i], " ");
		if (!trimmed || !ft_isvalidint(trimmed) || (ft_strlen(trimmed) > 1
				&& *trimmed == '0' && !ft_isspace(*(trimmed + 1)))
			|| ft_strchr(trimmed, ' ') || ft_atoi(trimmed) > 255
			|| ft_atoi(trimmed) < 0)
			ft_exit_error("Invalid color value");
		if (i == 0)
			color->red = ft_atoi(trimmed);
		else if (i == 1)
			color->green = ft_atoi(trimmed);
		else
			color->blue = ft_atoi(trimmed);
		ft_cautious_free((void **)&trimmed);
	}
	ft_free_2d_array((void ***)&colors, ft_arrlen(colors), 0);
}

void	parse_colors(char **map_filepath, t_specifications *specifications)
{
	char	*line;
	int		read_result;
	int		index;
	bool	counter_floor;
	bool	counter_ceiling;
	int		fd;

	counter_floor = false;
	counter_ceiling = false;
	fd = open(map_filepath, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Could not open file");
	while (1)
	{
		read_result = get_line(fd, &line);
		if (read_result <= 0)
			break;
		if (*line == '\0')
		{
			ft_cautious_free((void **)&line);
			continue;
		}
		index = 0;
		while (ft_isspace(line[index]))
			index++;
		if (ft_strnstr(line + index, F, ft_strlen(F)))
		{
			if (counter_floor)
			{
				ft_cautious_free((void **)&line);
				ft_exit_error("Duplicate color Identifier");
			}
			ft_parse_color(line + index, &specifications->floor_color);
			counter_floor = true;
		}
		else if (ft_strnstr(line + index, C, ft_strlen(C)))
		{
			if (counter_ceiling)
			{
				ft_cautious_free((void **)&line);
				ft_exit_error("Duplicate color Identifier");
			}
			ft_parse_color(line + index, &specifications->ceiling_color);
			counter_ceiling = true;
		}
		ft_cautious_free((void **)&line);
	}
	if (read_result < 0)
		ft_exit_error("Could not read file");
	if (specifications->floor_color.red == 256
		|| specifications->ceiling_color.red == 256)
		ft_exit_error("Missing floor or ceiling specifications");
	close(fd);
}

void	init_specifications(t_specifications *specifications)
{
	ft_memset(specifications, 0, sizeof(t_specifications));
	specifications->floor_color.red = 256;
	specifications->ceiling_color.red = 256;
	specifications->floor_color.green = 256;
	specifications->ceiling_color.green = 256;
	specifications->floor_color.blue = 256;
	specifications->ceiling_color.blue = 256;
}

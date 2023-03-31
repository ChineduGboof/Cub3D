/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:52:28 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/31 13:11:58 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game/image/image.h"

static int	too_many_commas(const char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count > 2)
		return (1);
	return (0);
}

void	ft_parse_color(char *line, t_color *color, int fd)
{
	char	**colors;
	char	*trimmed;
	int		i;
	size_t arr_len;

	i = -1;
	if (too_many_commas(line))
		ft_exit_error("Too many comma's present", fd);
	colors = ft_split(line + 2, ',');
	if (!colors || ft_arrlen(colors) != 3)
		ft_exit_error("Wrong number of color values", fd);
	while (colors[++i])
	{
		trimmed = ft_strtrim(colors[i], " ");
		if (!trimmed || !ft_isvalidint(trimmed) || (ft_strlen(trimmed) > 1
				&& *trimmed == '0' && !ft_isspace(*(trimmed + 1)))
			|| ft_strchr(trimmed, ' ') || ft_atoi(trimmed) > 255
			|| ft_atoi(trimmed) < 0)
			ft_exit_error("Invalid color value", fd);
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

void	parse_colors(char *map_filepath, t_specifications *specifications)
{
	char	*line;
	int		read_result;
	int		index;
	bool	counter_floor;
	bool	counter_ceiling;
	

	counter_floor = false;
	counter_ceiling = false;
	int		fd;

	fd = open(map_filepath, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Could not open map file", fd);
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
				ft_exit_error("Duplicate color Identifier", fd);
			}
			ft_parse_color(line + index, &specifications->floor_color, fd);
			counter_floor = true;
		}
		else if (ft_strnstr(line + index, C, ft_strlen(C)))
		{
			if (counter_ceiling)
			{
				ft_cautious_free((void **)&line);
				ft_exit_error("Duplicate color Identifier", fd);
			}
			ft_parse_color(line + index, &specifications->ceiling_color, fd);
			counter_ceiling = true;
		}
		ft_cautious_free((void **)&line);
	}
	if (read_result < 0)
		ft_exit_error("Could not read file", fd);
	if (specifications->floor_color.red == 256
		|| specifications->ceiling_color.red == 256)
		ft_exit_error("Missing floor or ceiling specifications", fd);
	close(fd);
}


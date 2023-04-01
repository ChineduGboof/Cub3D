/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:52:28 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/02 03:47:27 by oaydemir         ###   ########.fr       */
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
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	if (count > 2)
		return (1);
	return (0);
}

/*	Are the color numbers valid ? Are they within the 0 to 255 range ? */
void	check_color_values(char **colors, char *line, int fd)
{
	int		i;
	char	*trimmed;

	i = -1;
	while (colors[++i])
	{
		trimmed = ft_strtrim(colors[i], " ");
		if (!trimmed || !trimmed[0] || !ft_isvalidint(trimmed)
			|| (ft_strlen(trimmed) > 1
				&& *trimmed == '0' && !ft_isspace(*(trimmed + 1)))
			|| ft_strchr(trimmed, ' ') || ft_atoi(trimmed) > 255
			|| ft_atoi(trimmed) < 0 || ft_strlen(trimmed) > 3)
		{
			ft_cautious_free((void **)&line);
			ft_exit_error("Invalid color value", fd);
		}
		ft_cautious_free((void **)&trimmed);
	}
}

/*	We need to aasign the color values to the struct */
void	parse_color_values(char **colors, t_color *color, char *line, int fd)
{
	if (!colors || ft_arrlen(colors) != 3)
	{
		ft_cautious_free((void **)&line);
		ft_exit_error("Wrong number of color values", fd);
	}
	color->red = ft_atoi(colors[0]);
	color->green = ft_atoi(colors[1]);
	color->blue = ft_atoi(colors[2]);
	ft_free_2d_array((void ***)&colors, ft_arrlen(colors), 0);
}

/*	We need to split the color string and get the individual values */
void	ft_parse_color(char *line, t_color *color, int fd)
{
	char	**colors;

	if (too_many_commas(line))
	{
		ft_cautious_free((void **)&line);
		ft_exit_error("Too many comma's present", fd);
	}
	colors = ft_split(line + 2, ',');
	check_color_values(colors, line, fd);
	parse_color_values(colors, color, line, fd);
}

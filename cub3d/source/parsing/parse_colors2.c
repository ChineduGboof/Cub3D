/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:58:22 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/03 20:02:57 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game/image/image.h"

void	parse_floor_color(char *line, int arr[], int *counter_floor,
			t_specifications *specifications)
{
	if (ft_strnstr(line + arr[1], F, ft_strlen(F)) && (line + arr[1] + 1)
		&& (*(line + arr[1] + 1) == ' '))
	{
		if (*counter_floor)
		{
			ft_cautious_free((void **)&line);
			ft_exit_error("Duplicate color Identifier", arr[2]);
		}
		ft_parse_color(line + arr[1], &specifications->floor_color, arr[2]);
		(*counter_floor)++;
	}
}

void	parse_ceiling_color(char *line, int arr[], int *counter_ceiling,
			t_specifications *specifications)
{
	if (ft_strnstr(line + arr[1], C, ft_strlen(C)) && (line + arr[1] + 1)
		&& (*(line + arr[1] + 1) == ' '))
	{
		if (*counter_ceiling)
		{
			ft_cautious_free((void **)&line);
			ft_exit_error("Duplicate color Identifier", arr[2]);
		}
		ft_parse_color(line + arr[1], &specifications->ceiling_color, arr[2]);
		(*counter_ceiling)++;
	}
}

/*	Checks if get_line succesfully read a file */
void	check_parse_color_success(int arr[], int counters[2])
{
	if (arr[0] < 0)
		ft_exit_error("Could not read file", arr[2]);
	else if (counters[0] == 0 || counters[1] == 0)
		ft_exit_error("Missing color value", arr[2]);
	else if (counters[0] > 1 || counters[1] > 1)
		ft_exit_error("Too many color values", arr[2]);
	close(arr[2]);
}

int	skip_whitespace(char *line)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	return (i);
}

/**
 * counter[0] = counter_floor
 * counter[1] = counter_ceiling
 * arr[0] = read_result
 * arr[1] = index
 * arr[2] = fd
*/
void	parse_colors(char *map_filepath, t_specifications *specifications)
{
	char	*line;
	int		arr[3];
	int		counter[2];

	ft_bzero(arr, 3 * sizeof(int));
	ft_bzero(counter, 2 * sizeof(int));
	arr[2] = open(map_filepath, O_RDONLY);
	if (arr[2] < 0)
		ft_exit_msg("Could not open map file");
	while (1)
	{
		arr[0] = get_line(arr[2], &line);
		if (arr[0] <= 0)
			break ;
		if (*line == '\0')
		{
			ft_cautious_free((void **)&line);
			continue ;
		}
		arr[1] = skip_whitespace(line);
		parse_floor_color(line, arr, &(counter[0]), specifications);
		parse_ceiling_color(line, arr, &(counter[1]), specifications);
		ft_cautious_free((void **)&line);
	}
	check_parse_color_success(arr, counter);
}

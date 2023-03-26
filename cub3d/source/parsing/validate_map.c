/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:14:57 by gboof             #+#    #+#             */
/*   Updated: 2023/03/26 05:26:57 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// void	check_texture(char *line)
// {
// 	char	*path;
// 	int		fd;

// 	path = ft_strtrim(line + 2, " ");
// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_putstr_fd("Error: Invalid texture path\n", 2);
// 		exit(EXIT_FAILURE);
// 	}
// 	close(fd);
// 	free(path);
// }

// int	validate_color_format(char *line)
// {
// 	char	**rgb;
// 	int		r;
// 	int		g;
// 	int		b;

// 	rgb = ft_split(line, ',');
// 	if (ft_countwords(line, ',') != 3)
// 		return (-1);
// 	r = ft_atoi(rgb[0]);
// 	g = ft_atoi(rgb[1]);
// 	b = ft_atoi(rgb[2]);
// 	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
// 		return (-1);
// 	free_2d_array(rgb);
// 	return (0);
// }

// static void	validate_line(char *line)
// {
// 	int	j;

// 	j = 0;
// 	while (line[j])
// 	{
// 		if (line[j] == ' ')
// 			j++;
// 		else if (ft_isnumeric(line[j]))
// 		{
// 			if (validate_color_format(line + j) == -1)
// 				error_exit("Invalid color format in map.");
// 			if (ft_countwords(line + j, ',') != 3)
// 				error_exit("Error: Too many or too few arguments for color.");
// 			check_range(ft_split(line + j, ','));
// 			break ;
// 		}
// 		else
// 			error_exit("Invalid character in map.");
// 	}
// }

// static void	validate_map_content(int fd)
// {
// 	char	*line;
// 	int		i;

// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		validate_line(line);
// 		free(line);
// 		i++;
// 		line = get_next_line(fd);
// 	}
// 	if (i < 3)
// 		error_exit("Map is too small.");
// }

void	validate_map(char *cub_file)
{
	int	fd;

	fd = open(cub_file, O_RDONLY);
	check_identifiers(fd);
	// validate_map_content(fd);
	close(fd);
}

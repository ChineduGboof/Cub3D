/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:14:57 by gboof             #+#    #+#             */
/*   Updated: 2023/03/27 13:12:16 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
check_texture() checks if the texture path in a configuration 
line is valid by attempting to open the file.
*/
void	check_texture(char *line)
{
	char	*path;
	int		fd;

	path = ft_strtrim(line + 2, " ");
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: Invalid texture path\n", 2);
		exit(EXIT_FAILURE);
	}
	close(fd);
	free(path);
}

/*
validate_color_format() validates the format of a color string 
by checking if it has three comma-separated components, 
and if the components are valid integers between 0 and 255.
*/
int	validate_color_format(char *line)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(line, ',');
	if (ft_countwords(line, ',') != 3)
		return (-1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	free_2d_array(rgb);
	return (0);
}

/*
validate_line() validates a line of the map by checking if it contains 
a valid color string, an invalid character, or an incomplete or 
extra argument in the color string.
 If it is invalid, it raises an error.
*/
static void	validate_line(char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == ' ')
			j++;
		else if (ft_isnumeric(line[j]))
		{
			if (validate_color_format(line + j) == -1)
				error_exit("Invalid color format in map.");
			if (ft_countwords(line + j, ',') != 3)
				error_exit("Error: Too many or too few arguments for color.");
			// check_range(ft_split(line + j, ','));
			break ;
		}
		else
			error_exit("Invalid character in map.");
	}
}

/*
validate_map_content() validates the content of the map by 
checking each line using validate_line()
*/
static void	validate_map_content(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		validate_line(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	if (i < 3)
		error_exit("Map is too small.");
}

void	validate_map(char *cub_file)
{
	// check for addition of random identifier with complete correct identifier
	// check for anything after and inside map
	check_identifiers(cub_file);
	//validate the texture file paths(.xpm) and only one word
	validate_texture_file_path(cub_file);
	//validate the colors
	// validate_color(cub_file);
	//validate the map content for spaces, player position and walls
	// validate_map_content(fd);
}

#include "libft.h"
#include <stdlib.h>

void check_line(char *line, char **ids, int num_ids) 
{
    int i = 0, line_index = 0, is_valid = 0;

    while (ft_isspace(line[line_index]))
        line_index++;

    while (i < num_ids && !is_valid) {
        if (ft_strcmp(line + line_index, ids[i]) == 0 && (line[line_index + ft_strlen(ids[i])] == ' ' || line[line_index + ft_strlen(ids[i])] == '\t' || line[line_index + ft_strlen(ids[i])] == '\0')) {
            is_valid = 1;
        } else {
            i++;
            line_index = 0;

            while (ft_isspace(line[line_index]))
                line_index++;
        }
    }

    if (!is_valid) {
        free(line);
        exit(0);
    }
}

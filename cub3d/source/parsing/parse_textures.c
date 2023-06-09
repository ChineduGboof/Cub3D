/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:51:46 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/06 12:11:45 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_valid_identifier(char *str)
{
	char	**array;
	size_t	array_index;
	bool	is_valid;

	is_valid = (true);
	array = ft_split_charset(str, " \t");
	if (!array)
		is_valid = false;
	else if (ft_arrlen(array) != 2)
		is_valid = false;
	else if (ft_strncmp(array[1] + (ft_strlen(array[1]) - 4), ".xpm", 4) != 0)
		is_valid = false;
	else if (ft_strncmp(array[0], "NO", 3) != 0
		&& ft_strncmp(array[0], "SO", 3) != 0
		&& ft_strncmp(array[0], "WE", 3) != 0
		&& ft_strncmp(array[0], "EA", 3) != 0)
		is_valid = false;
	ft_free_2d_array((void ***)&array, -1, true);
	return (is_valid);
}

void	print_specifications(const t_specifications *specifications)
{
	if (specifications->north_texture == NULL)
		ft_exit_msg("missing north texture specification");
	if (specifications->south_texture == NULL)
		ft_exit_msg("missing south texture specification");
	if (specifications->west_texture == NULL)
		ft_exit_msg("missing west texture specification");
	if (specifications->east_texture == NULL)
		ft_exit_msg("missing east texture specification");
}

int	open_filepath(char *argument)
{
	int	fd;

	fd = open(argument, O_RDONLY);
	if (fd == -1)
	{
		ft_exit_msg("Could not open map file");
	}
	return (fd);
}

void	parse_textures(char *map_file_path,
		t_specifications *specifications)
{
	int		fd;
	int		read_result;
	int		index;
	char	*line;

	fd = open_filepath(map_file_path);
	while (1)
	{
		read_result = get_line(fd, &line);
		if (read_result <= 0)
			break ;
		if (*line == '\0')
		{
			ft_cautious_free((void **)&line);
			continue ;
		}
		index = 0;
		while (ft_isspace(line[index]))
			index++;
		if (is_valid_identifier(line + index))
			parse_identifier_line(line + index, specifications, fd);
		ft_cautious_free((void **)&line);
	}
	close(fd);
	print_specifications(specifications);
}

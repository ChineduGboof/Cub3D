/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:51:46 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/02 00:31:52 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_valid_identifier(const char *str)
{
	size_t		len;
	size_t		path_len;
	const char	*path;

	len = ft_strlen(str);
	if (len < 8)
		return (false);
	if (ft_strnstr(str, NO, ft_strlen(NO)) || ft_strnstr(str, SO, ft_strlen(SO))
		|| ft_strnstr(str, WE, ft_strlen(WE))
		|| ft_strnstr(str, EA, ft_strlen(EA)))
	{
		path = str + 3;
		path_len = ft_strlen(path);
		if (ft_strncmp(path + path_len - 4, ".xpm", 4) != 0)
			return (false);
		return (true);
	}
	return (false);
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
	printf("North texture: %s\n", specifications->north_texture);
	printf("South texture: %s\n", specifications->south_texture);
	printf("West texture: %s\n", specifications->west_texture);
	printf("East texture: %s\n", specifications->east_texture);
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

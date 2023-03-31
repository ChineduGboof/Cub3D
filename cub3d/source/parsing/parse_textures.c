/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:51:46 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/31 13:10:25 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool is_valid_identifier(const char *str)
{
	size_t	len;
	size_t	path_len;

	len = ft_strlen(str);
	if (len < 8)
		return false;
	if (ft_strnstr(str, NO, ft_strlen(NO)) ||
		ft_strnstr(str, SO, ft_strlen(SO)) ||
		ft_strnstr(str, WE, ft_strlen(WE)) ||
		ft_strnstr(str, EA, ft_strlen(EA)))
	{
		const char *path = str + 3;
		path_len = ft_strlen(path);
		if (ft_strncmp(path + path_len - 4, ".xpm", 4) != 0)
			return false;
		return true;
	}
	return false;
}

	// if identifier is valid, extract it and the
void extract_identifier_and_path(const char *str, char **identifier, char **path, int fd)
{
	char	*trimmed_str;
	char	*space_ptr;

	trimmed_str = ft_strtrim(str, " ");
	if (!trimmed_str)
		ft_exit_error("could not allocate memory", fd);

	space_ptr = ft_strchr(trimmed_str, ' ');
	if (!space_ptr)
		ft_exit_error("invalid identifier line", fd);
	*space_ptr = '\0';

	// if identifier is valid, extract it and the path
	*identifier = ft_strdup(trimmed_str);
	*path = ft_strdup(space_ptr + 1);
	if (!(*identifier) || !(*path))
		ft_exit_error("could not allocate memory", fd);
	free(trimmed_str);
}

void parse_identifier_line(const char *line, t_specifications *specifications, int fd)
{
	char *identifier;
	char *path;

	extract_identifier_and_path(line, &identifier, &path, fd);

	if (ft_strncmp(identifier, NO, 2) == 0)
	{
		if (specifications->north_texture != NULL)
			ft_exit_error("duplicate north texture specification", fd);
		specifications->north_texture = path;
	}
	else if (ft_strncmp(identifier, SO, 2) == 0)
	{
		if (specifications->south_texture != NULL)
			ft_exit_error("duplicate south texture specification", fd);
		specifications->south_texture = path;
	}
	else if (ft_strncmp(identifier, WE, 2) == 0)
	{
		if (specifications->west_texture != NULL)
			ft_exit_error("duplicate west texture specification", fd);
		specifications->west_texture = path;
	}
	else if (ft_strncmp(identifier, EA, 2) == 0)
	{
		if (specifications->east_texture != NULL)
			ft_exit_error("duplicate east texture specification", fd);
		specifications->east_texture = path;
	}
	else
		ft_exit_error("invalid identifier", fd);
	ft_cautious_free((void **)&identifier);
}

void print_specifications(const t_specifications *specifications, int fd)
{
	if (specifications->north_texture == NULL)
		ft_exit_error("missing north texture specification", fd);
	if (specifications->south_texture == NULL)
		ft_exit_error("missing south texture specification", fd);
	if (specifications->west_texture == NULL)
		ft_exit_error("missing west texture specification", fd);
	if (specifications->east_texture == NULL)
		ft_exit_error("missing east texture specification", fd);

	printf("North texture: %s\n", specifications->north_texture);
	printf("South texture: %s\n", specifications->south_texture);
	printf("West texture: %s\n", specifications->west_texture);
	printf("East texture: %s\n", specifications->east_texture);
}

void parse_textures(const char *map_file_path, t_specifications *specifications)
{
	int		fd;
	int		read_result;
	int		index;
	char	*line;

	fd = open(map_file_path, O_RDONLY);
	if (fd == -1)
		ft_exit_error("Could not open file", fd);
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
		if (is_valid_identifier(line + index))
			parse_identifier_line(line + index, specifications, fd);
		ft_cautious_free((void **)&line);
	}
	print_specifications(specifications, fd);
	close(fd);

	// print specifications

	// free specifications
	ft_cautious_free((void **)&specifications->north_texture);
	ft_cautious_free((void **)&specifications->south_texture);
	ft_cautious_free((void **)&specifications->west_texture);
	ft_cautious_free((void **)&specifications->east_texture);
}
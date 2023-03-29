/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:51:46 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/29 21:22:21 by cegbulef         ###   ########.fr       */
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
void extract_identifier_and_path(const char *str, char **identifier, char **path)
{
	char	*trimmed_str;
	char	*space_ptr;

	trimmed_str = ft_strtrim(str, " ");
	if (!trimmed_str)
	{
		perror("Error: could not allocate memory");
		exit(EXIT_FAILURE);
	}

	space_ptr = ft_strchr(trimmed_str, ' ');
	if (!space_ptr)
	{
		fprintf(stderr, "Error: invalid identifier line: %s\n", str);
		exit(EXIT_FAILURE);
	}
	*space_ptr = '\0';

	// if identifier is valid, extract it and the path
	*identifier = ft_strdup(trimmed_str);
	*path = ft_strdup(space_ptr + 1);
	if (!(*identifier) || !(*path))
	{
		perror("Error: could not allocate memory");
		exit(EXIT_FAILURE);
	}
	free(trimmed_str);
}

void parse_identifier_line(const char *line, t_specifications *specifications)
{
	char *identifier;
	char *path;

	extract_identifier_and_path(line, &identifier, &path);

	if (ft_strncmp(identifier, NO, 2) == 0)
	{
		if (specifications->north_texture != NULL)
		{
			fprintf(stderr, "Error: duplicate north texture specification\n");
			exit(EXIT_FAILURE);
		}
		specifications->north_texture = path;
	}
	else if (ft_strncmp(identifier, SO, 2) == 0)
	{
		if (specifications->south_texture != NULL)
		{
			fprintf(stderr, "Error: duplicate south texture specification\n");
			exit(EXIT_FAILURE);
		}
		specifications->south_texture = path;
	}
	else if (ft_strncmp(identifier, WE, 2) == 0)
	{
		if (specifications->west_texture != NULL)
		{
			fprintf(stderr, "Error: duplicate west texture specification\n");
			exit(EXIT_FAILURE);
		}
		specifications->west_texture = path;
	}
	else if (ft_strncmp(identifier, EA, 2) == 0)
	{
		if (specifications->east_texture != NULL)
		{
			fprintf(stderr, "Error: duplicate east texture specification\n");
			exit(EXIT_FAILURE);
		}
		specifications->east_texture = path;
	}
	else
	{
		fprintf(stderr, "Error: invalid identifier: %s\n", identifier);
		exit(EXIT_FAILURE);
	}
	ft_cautious_free((void **)&identifier);
}

void print_specifications(const t_specifications *specifications)
{
	if (specifications->north_texture == NULL)
	{
		fprintf(stderr, "Error: missing north texture specification\n");
		exit(EXIT_FAILURE);
	}
	if (specifications->south_texture == NULL)
	{
		fprintf(stderr, "Error: missing south texture specification\n");
		exit(EXIT_FAILURE);
	}
	if (specifications->west_texture == NULL)
	{
		fprintf(stderr, "Error: missing west texture specification\n");
		exit(EXIT_FAILURE);
	}
	if (specifications->east_texture == NULL)
	{
		fprintf(stderr, "Error: missing east texture specification\n");
		exit(EXIT_FAILURE);
	}

	// printf("North texture: %s\n", specifications->north_texture);
	// printf("South texture: %s\n", specifications->south_texture);
	// printf("West texture: %s\n", specifications->west_texture);
	// printf("East texture: %s\n", specifications->east_texture);
}

void parse_textures(const char *map_file_path, t_specifications *specifications)
{
	int		fd;
	int		read_result;
	int		index;
	char	*line;

	fd = open(map_file_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error: could not open map file");
		exit(EXIT_FAILURE);
	}
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
			parse_identifier_line(line + index, specifications);
		else
		{
			//anything not valid identifier should be saved to the map file
			// printf("detecting colors here\n");
			// fprintf(stderr, "Error: invalid identifier line: %s\n", line);
			// exit(EXIT_FAILURE);	
		}
		ft_cautious_free((void **)&line);
	}
	close(fd);

	// print specifications
	print_specifications(specifications);

	// free specifications
	ft_cautious_free((void **)&specifications->north_texture);
	ft_cautious_free((void **)&specifications->south_texture);
	ft_cautious_free((void **)&specifications->west_texture);
	ft_cautious_free((void **)&specifications->east_texture);
}
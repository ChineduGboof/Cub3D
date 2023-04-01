/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:58:09 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/01 22:58:17 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

	// if identifier is valid, extract it and the path
void	extract_identifier_and_path(const char *str, char **identifier,
		char **path, int fd)
{
	char	*trimmed_str;
	char	*space_ptr;

	trimmed_str = ft_strtrim(str, " ");
	if (!trimmed_str)
		ft_exit_error("could not allocate memory", fd);
	space_ptr = ft_strchr(trimmed_str, ' ');
	if (!space_ptr)
	{
		ft_cautious_free((void **)&trimmed_str);
		ft_exit_error("invalid identifier line", fd);
	}
	*space_ptr = '\0';
	*identifier = ft_strdup(trimmed_str);
	*path = ft_strdup(space_ptr + 1);
	if (!(*identifier) || !(*path))
	{
		ft_cautious_free((void **)&trimmed_str);
		ft_cautious_free((void **)identifier);
		ft_cautious_free((void **)path);
		ft_exit_error("could not allocate memory", fd);
	}
	ft_cautious_free((void **)&trimmed_str);
}

void	set_texture_path(char **texture, char *path, char *identifier, int fd)
{
	char	*error_message;

	if (*texture != NULL)
	{
		error_message = ft_strjoin("duplicate ", identifier);
		ft_exit_error(error_message, fd);
		ft_cautious_free((void **)&error_message);
	}
	*texture = path;
}

void	parse_identifier_line(const char *line,
		t_specifications *specifications, int fd)
{
	char	*identifier;
	char	*path;

	extract_identifier_and_path(line, &identifier, &path, fd);
	if (ft_strncmp(identifier, NO, 2) == 0)
		set_texture_path(&specifications->north_texture, path,
			"north texture specification", fd);
	else if (ft_strncmp(identifier, SO, 2) == 0)
		set_texture_path(&specifications->south_texture, path,
			"south texture specification", fd);
	else if (ft_strncmp(identifier, WE, 2) == 0)
		set_texture_path(&specifications->west_texture, path,
			"west texture specification", fd);
	else if (ft_strncmp(identifier, EA, 2) == 0)
		set_texture_path(&specifications->east_texture, path,
			"east texture specification", fd);
	else
		ft_exit_error("invalid identifier", fd);
	ft_cautious_free((void **)&identifier);
}

void	free_textures(t_specifications *specifications)
{
	ft_cautious_free((void **)&specifications->north_texture);
	ft_cautious_free((void **)&specifications->south_texture);
	ft_cautious_free((void **)&specifications->west_texture);
	ft_cautious_free((void **)&specifications->east_texture);
	free_map(specifications, EXIT_SUCCESS);
}

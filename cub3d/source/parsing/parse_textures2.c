/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:58:09 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/03 15:07:20 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	extract_identifier_and_path(char *str, char **identifier,
		char **path, int fd)
{
	char	**array;

	array = ft_split_charset(str, " \t");
	if (!array)
		ft_exit_error("could not allocate memory", fd);
	*identifier = array[0];
	*path = array[1];
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

void	parse_identifier_line(char *line,
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

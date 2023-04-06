/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:58:09 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/06 12:17:53 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	extract_identifier_and_path(char *str, char **identifier,
		char **path, int fd)
{
	char	**array;

	array = ft_split_charset(str, " \t");
	if (!array)
	{
		ft_cautious_free((void **)&str);
		ft_exit_error("could not allocate memory", fd);
	}
	*identifier = array[0];
	*path = array[1];
	ft_cautious_free_double_ptr((void ***)&array);
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
	{
		ft_cautious_free((void **)&identifier);
		ft_cautious_free((void **)&path);
		ft_cautious_free((void **)&line);
		ft_exit_error("invalid identifier", fd);
	}
	ft_cautious_free((void **)&identifier);
}

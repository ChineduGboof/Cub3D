/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:38:41 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/01 19:50:33 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* Is the map an actual file or directory ? */
void	validate_map_file(const char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
	{
		ft_putstr_fd("Error: Is a directory\n", 2);
		close(fd);
		exit(EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Not a Map file\n", 2);
		close(fd);
		exit(EXIT_FAILURE);
	}
	close(fd);
}

/* Does the map have a valid file extension ? */
void	check_map_file_ext(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".cub", 4) != 0 || ft_strlen(ext) != 4)
	{
		ft_putstr_fd("Error: Invalid Map Extension\n", 2);
		exit(EXIT_FAILURE);
	}
}

/* Does the map file-path need validation ? */
void	validate_argument(char *map_file_path)
{
	validate_map_file(map_file_path);
	check_map_file_ext(map_file_path);
}

/* Is the file empty ?*/
bool	is_empty_file(char *argument)
{
	int		fd;
	char	*line;

	fd = open(argument, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: could not open file", STDERR_FILENO);
		return (true);
	}
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (true);
	}
	close(fd);
	return (false);
}

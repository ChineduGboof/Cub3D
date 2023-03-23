/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:38:41 by cegbulef          #+#    #+#             */
/*   Updated: 2023/03/23 20:29:43 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* This function checks if the map file is actually a file 
	and handles cases where a directory is passed for a file */
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

/* This function checks if the given file has a valid file extension */
void	check_map_file_ext(char *file)
{
	char	*ext;

	ext = ft_strrchr(file, '.');
	if (!ext || ft_strncmp(ext, ".cub", 4) != 0 || ft_strlen(ext) != 4)
	{
		ft_putstr_fd("Error: Invalid Map Extension\n", 2);
		exit(1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:48:18 by gboof             #+#    #+#             */
/*   Updated: 2023/04/01 19:50:05 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game/image/image.h"

int	open_file(char *argument)
{
	int	fd;

	fd = open(argument, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: could not open file", STDERR_FILENO);
		return (true);
	}
	return (fd);
}

void	init_specs(char **specifications)
{
	specifications[0] = "NO";
	specifications[1] = "SO";
	specifications[2] = "WE";
	specifications[3] = "EA";
	specifications[4] = "F";
	specifications[5] = "C";
}

bool	check_for_one(int fd)
{
	char	*line;

	line = NULL;
	while (get_line(fd, &line) > 0)
	{
		if (ft_strncmp(line, "1", 1) == 0)
		{
			free(line);
			return (true);
		}
		free(line);
	}
	return (false);
}

bool	check_for_missing_specification(int fd, char *specs[])
{
	int		i;
	bool	found_spec;
	char	*line;

	i = 0;
	while (i < 6)
	{
		found_spec = false;
		line = NULL;
		while (get_line(fd, &line) > 0)
		{
			if (ft_strncmp(line, specs[i], ft_strlen(specs[i])) == 0)
			{
				found_spec = true;
				ft_cautious_free((void **)&line);
				break ;
			}
			free(line);
		}
		if (!found_spec)
			return (true);
		i++;
	}
	return (false);
}

bool	has_missing_specification(char *argument)
{
	char	*specifications[6];
	int		fd;
	bool	missing_spec;
	bool	has_one;

	init_specs(specifications);
	fd = open_file(argument);
	missing_spec = check_for_missing_specification(fd, specifications);
	has_one = check_for_one(fd);
	close(fd);
	return (missing_spec || !has_one);
}

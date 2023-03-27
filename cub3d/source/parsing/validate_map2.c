/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:50:53 by gboof             #+#    #+#             */
/*   Updated: 2023/03/26 23:31:58 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
check_map_line: This function is used to validate each line of the map in the configuration file.
It checks if there is a space character in the line, which indicates an invalid map,
and if there are more than three arguments in the line, which is also invalid.
*/
static void	check_map_line(char *line)
{
	if (ft_strchr(line, ' '))
		error_exit("Error: Invalid map");
	if (ft_strlen(line) == 0)
		return ;
	if (ft_countwords(line, ' ') > 3)
		error_exit("Error: Too many arguments");
}

/*
check_first_map_line: This function is used to check the first line of the map in the configuration file.
It checks if the line starts with "1" or a space character.
If the line starts with something else, it is considered invalid.
*/
static void	check_first_map_line(char *line, int *map_started)
{
	printf("here now\n");
	if (ft_strncmp(line, "1", 1) != 0 && ft_strncmp(line, " ", 1) != 0)
		error_exit("Error: Invalid map");
	*map_started = 1;
}

/*
check_identifier: This function is used to check if an identifier 
in the configuration file is valid. 
It takes an array of valid identifiers and checks if 
the current line matches one of them. If it does, 
it checks if there are no more than two arguments in the line. 
If it doesn't match any of the valid identifiers, 
it is considered invalid.
*/
static void	check_identifier(char *line, char **ids)
{
	int	i;

	i = 0;
	while (ids[i])
	{
		if (ft_strncmp(ids[i], line, ft_strlen(ids[i])) == 0)
		{
			if (ft_countwords(line, ' ') != 2)
				error_exit("Error: Too many arguments");
			break ;
		}
		i++;
	}
	if (!ids[i])
		error_exit("Error: Invalid identifier");
}

/*
check_identifiers: This function is used to validate all the identifiers 
in the configuration file. It reads each line of the file, 
validates the first line as the map, 
and then checks if the rest of the lines are valid identifiers.
*/

int	array_num(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	check_uppercase(char* str)
{
    int i = 0;
    while (str[i] != '\0')
	{
        if (!(str[i] >= 65 && str[i] <= 90))
            return 0; // not a valid uppercase alphabet
        i++;
    }
    return 1; // valid uppercase alphabet
}

int	only_spaces(char* str)
{
	while (*str != '\0')
	{
		if (!ft_isspace(*str))
			return 0; // not all spaces
		str++;
	}
	return 1; // all spaces
}

int	chk_if_identifiers_present(int *arr)
{
	int i;

	i = -1;
	while (++i < 6)
		if (arr[i] != 1)
			return 0;
	return 1;
}
// trach the number of valid id's found
// track if a valid id repeats
// i[0] => NO
// i[1] => SO
// i[2] => WE
// i[3] => EA
// i[4] => F
// I[5] => C
// I[6] => num of valid id's
// checks if the identifiers are valid and no duplicates
// I splitted using # to solve for args like "EAtextures/xpm/wall_5.xpm"
void	check_identifiers(char *cub_file)
{
	char	**ids;
	int		line_index;
	int		num_id;
	bool	map_started;
	char	*line;
	int 	id_tag[7];	//array of identifier id
	int		j;
	int		fd;

	fd = open(cub_file, O_RDONLY);
    ft_bzero(id_tag, 7 * sizeof(int));
	map_started = false;
	ids = ft_split(VALID_IDS, '#');
	num_id = array_num(ids);
	line = get_next_line(fd);
	while (line)
	{
		if (!only_spaces(line) && !map_started)	// if not an empty line then enter
		{
			j = -1;
			while (++j <= num_id)	//loops thru the line and if it finds a valid identifier it increments the field for it
			{
				line_index = 0;
				while (ft_isspace(line[line_index]))	// loop thru any space in the line gotten
					line_index++;
				if (ft_strncmp(line + line_index, ids[j], ft_strlen(ids[j])) == 0)
				{
					id_tag[j]++;
					id_tag[6]++;
					break ;
				}
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	if (chk_if_identifiers_present(id_tag) != 1)
	{
		free(ids);
		error_exit("Error: Invalid identifier");
	}
	printf("valid identifiers\n");
	free(ids);
	close(fd);
}

		// if (line)
		// if (ft_isprint(line[0]))
		// {
		// 	if (map_started)
		// 		check_map_line(line);
		// 	else
		// 		check_first_map_line(line, &map_started);
		// 	check_identifier(line, ids);
		// }
// this function finds out where the map starts from
// change the while loop to loop thru the whole map
		// while (j < num_id)
		// {
		// 	if (ft_strncmp(line, ids[j], ft_strlen(ids[j])) == 0) 
		// 		map_started = 1;
		// }

/*
	if (ft_strncmp(line, "NO", 2) == 0
		|| ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0
		|| ft_strncmp(line, "EA", 2) == 0
		|| ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0)
*/


void	validate_texture_file_path(char *cub_file)
{
	// check if the texture file opens and the .xpm
	char	**ids;
	int		line_index;
	char	*line;
	int		j;
	int		fd;

	fd = open(cub_file, O_RDONLY);
	ids = ft_split(VALID_IDS, '#');
	line = get_next_line(fd);
	while (line)
	{
		if (!only_spaces(line))	// if not an empty line then enter
		{
			j = -1;
			while (++j < 4)	//loops thru the line and if it finds a valid identifier it increments the field for it
			{
				line_index = 0;
				while (ft_isspace(line[line_index]))	// loop thru any space in the line gotten
					line_index++;
				if (ft_strncmp(line + line_index, ids[j], ft_strlen(ids[j])) == 0)
				{
					if (ft_countwords(line, ' ') != 2)
					{
						free(line);
						free(ids);
						error_exit("Error: Too many arguments");
					}
					break ;
				}
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	printf("valid textures\n");
	free(ids);
	close(fd);
}

void	validate_color(char *cub_file)
{
	// char	**ids = NULL;
	char	**rgb = NULL;
	int		line_index;
	char	*line;
	int		j;
	int		fd;
	int		rgb_num;
	int		r;
	int		g;
	int		b;

	fd = open(cub_file, O_RDONLY);
	// ids = ft_split(VALID_IDS, '#');
	line = get_next_line(fd);
	while (line)
	{
		printf("line: %s\n", line);
		if (!only_spaces(line))	// if not an empty line then enter
		{
			line_index = 0;
			while (ft_isspace(line[line_index]))	// loop thru any space in the line gotten
				line_index++;
			if (ft_strncmp(line + line_index, "F ", 2) == 0)
			{
				printf("in now");
					// rgb = ft_split(line, ',');
					// rgb_num = array_num(rgb);
					// printf("rgb number %d\n", rgb_num);
					// if (rgb_num == 3)
					// {
					// 	r = ft_atoi(rgb[0]);
					// 	g = ft_atoi(rgb[1]);
					// 	b = ft_atoi(rgb[2]);
					// 	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
					// 	{
					// 		free(line);
					// 		free_2d_array(rgb);
					// 		error_exit("Error: Invalid Color arguments");
					// 	}
					// 	printf("valid color\n");
					// }
					// else
					// {
					// 	free_2d_array(rgb);
					// 	free(line);
					// 	error_exit("Error: Invalid Color arguments");
					// }
			}
			// if (ft_strncmp(line + line_index, "C ", 2) == 0)
			// {
				
			// }
			break;
		}
		free(line);
		line = get_next_line(fd);
	}
	// printf("valid colors\n");
	// free(ids);
	close(fd);
}

// void	validate_color(char *cub_file)
// {
// 	char	**ids;
// 	char	**rgb = NULL; // Initialize to NULL to avoid uninitialized access
// 	int		line_index;
// 	char	*line = NULL; // Initialize to NULL to avoid uninitialized access
// 	int		j;
// 	int		fd;
// 	int		rgb_num;
// 	int		r;
// 	int		g;
// 	int		b;

// 	fd = open(cub_file, O_RDONLY);
// 	ids = ft_split(VALID_IDS, '#');
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		if (!only_spaces(line))
// 		{
// 			// j = -1;
// 			int k = 3;
// 			while (++k < 6)
// 			{
// 				printf("ids[k]: %s\n", ids[k]);
// 				line_index = 0;
// 				printf("j: %d\n", j);
// 				while (ft_isspace(line[line_index]))
// 					line_index++;
// 				printf("line_index: %d\n", line_index);
// 				printf("line + line_index %s\n", line + line_index);
// 				if (ft_strncmp(line + line_index, ids[k], 2) == 0)
// 				{
// 					printf("here now\n");
// 					printf("ids[k]: %s\n", ids[k]);
// 					printf("line %s\n", line + line_index);
// 					rgb = ft_split(line, ',');
// 					rgb_num = array_num(rgb);
// 					printf("rgb number %d\n", rgb_num);
// 					if (rgb_num == 3)
// 					{
// 						r = ft_atoi(rgb[0]);
// 						g = ft_atoi(rgb[1]);
// 						b = ft_atoi(rgb[2]);
// 						if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
// 						{
// 							free(line);
// 							free_2d_array(ids); // Free ids before exiting
// 							free_2d_array(rgb);
// 							error_exit("Error: Too many arguments");
// 						}
// 						break;
// 					}
// 					else
// 					{
// 						free_2d_array(rgb);
// 						free(line);
// 						free_2d_array(ids); // Free ids before exiting
// 						error_exit("Error: Too many arguments");
// 					}
// 				}
// 			}
// 		}
// 		free_2d_array(rgb); // Free rgb at the end of each loop iteration
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	printf("valid textures\n");
// 	free_2d_array(ids); // Free ids at the end of the function
// 	close(fd);
// }

// int only_spaces(char* str)
// {
// 	if (str == NULL) // Check for null input
// 		return 1;

// 	while (*str != '\0')
// 	{
// 		if (!ft_isspace(*str))
// 			return 0;
// 		str++;
// 	}
// 	return 1;
// }

/*
check_range: This function is used to check if the RGB values of a color
 in the configuration file are valid. 
 It checks if each RGB value is a number and within the range of 0-255,
 and if the length of the value is not more than 3. 
 If any of these conditions are not met, the color is 
 considered invalid.
*/
void	check_range(char **rgb)
{
	int		i;
	long	val;

	i = -1;
	while (++i < 3)
	{
		if (!ft_isnumeric(*rgb[i]))
		{
			ft_putstr_fd("Error: Non-numeric color value\n", 2);
			exit(EXIT_FAILURE);
		}
		val = ft_atol(rgb[i]);
		if (val < 0 || val > 255 || ft_strlen(rgb[i]) > 3)
		{
			ft_putstr_fd("Error: Invalid color range\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

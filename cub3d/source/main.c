/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:15:33 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/24 14:00:57 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_specifications	fake_parse(char *cub_file)
{
	t_specifications	specifications = { 0 };
	//1. check if the identifiers are valid
	//2. Check that there are no duplicate identifiers
	//3. Check that the map ends the file
	//4. Make sure there is only one player
	//5. Store the map in the char** map
	//6. Store the texture paths in the NSEW array
	//7. Store the colors in the color struct
	
	return (specifications);
}
	

// void init_str

int	main(int argc, char **argv)
{
	t_specifications	specifications;
	
	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	// specifications should be a struct that contains all the information
	// specifications = parse(argv[1]);
	// validate_map_file checks if the map file is a valid file
	validate_map_file(argv[1]);
	// check_map_file_ext checks for valid file extension
	check_map_file_ext(argv[1]);
	specifications = fake_parse(argv[1]);
	init_struct(&specifications);
	run_game(specifications);
	(void)argv;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboof <gboof@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:15:33 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/28 09:28:52 by gboof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_specifications	fake_parse()
{
	t_specifications	specifications = { 0 };
	
	return (specifications);
}
	
// void init_str
// run main with ./cub3D ./maps/north.cub
int	main(int argc, char **argv)
{
	int	fd;
	t_specifications	specifications;
	
	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	// specifications should be a struct that contains all the information
	// validate_map_file checks if the map file is a valid file
	validate_map_file(argv[1]);
	// check_map_file_ext checks for valid file extension
	check_map_file_ext(argv[1]);

	// start from here
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_exit_error("Could not open file");
	init_specifications(&specifications);
	parse_specifications(fd, &specifications);
	printf("Floor color: R:%d, G:%d, B:%d\n", \
		specifications.floor_color.red, \
		specifications.floor_color.green, \
		specifications.floor_color.blue);
	printf("Ceiling color: R:%d, G:%d, B:%d\n", \
		specifications.ceiling_color.red, \
		specifications.ceiling_color.green, \
		specifications.ceiling_color.blue);

	specifications = fake_parse();
	// init_struct(&specifications);
	// run_game(specifications);
	// (void)argv; (void)argc;
	return (0);
}

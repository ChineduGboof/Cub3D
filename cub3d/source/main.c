/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:15:33 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/29 21:22:28 by cegbulef         ###   ########.fr       */
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
	t_specifications	specifications;
	
	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	// specifications should be a struct that contains all the information
	validate_map_file(argv[1]);
	check_map_file_ext(argv[1]);
	init_specifications(&specifications);
	parse_colors(argv[1], &specifications);
	parse_textures(argv[1], &specifications);
	parse_map(argv[1], &specifications);

	//prints the colors
	// printf("Floor color: R:%d, G:%d, B:%d\n", \
	// 	specifications.floor_color.red, \
	// 	specifications.floor_color.green, \
	// 	specifications.floor_color.blue);
	// printf("Ceiling color: R:%d, G:%d, B:%d\n", \
	// 	specifications.ceiling_color.red, \
	// 	specifications.ceiling_color.green, \
	// 	specifications.ceiling_color.blue);

	specifications = fake_parse();
	// init_struct(&specifications);
	// run_game(specifications);
	// (void)argv; (void)argc;
	return (0);
}

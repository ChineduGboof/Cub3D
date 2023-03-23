/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cegbulef <cegbulef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:15:33 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/23 20:32:30 by cegbulef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_specifications	fake_parse(void)
{
	t_specifications	specifications = { 0 };
	return (specifications);
}
	

int	main(int argc, char **argv)
{
	t_specifications	specifications;
	
	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments", STDERR_FILENO);
		return (1);
	}
	// specifications should be a struct that contains all the information
	// specifications = parse(argv[1]);
	// validate_map_file checks if the map file is a valid file
	validate_map_file(argv[1]);
	// check_map_file_ext checks for valid file extension
	check_map_file_ext(argv[1]);
	specifications = fake_parse();
	run_game(specifications);
	(void)argv;
}

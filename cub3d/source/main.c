/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:15:33 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 09:11:10 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_specifications	specifications;
	
	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	validate_argument(argv[1]);
	parsing(argv[1], &specifications);
	

	// prints the colors
	printf("Floor color: R:%d, G:%d, B:%d\n", \
		specifications.floor_color.red, \
		specifications.floor_color.green, \
		specifications.floor_color.blue);
	printf("Ceiling color: R:%d, G:%d, B:%d\n", \
		specifications.ceiling_color.red, \
		specifications.ceiling_color.green, \
		specifications.ceiling_color.blue);

	// init_struct(&specifications);
	run_game(specifications);
	return (0);
}

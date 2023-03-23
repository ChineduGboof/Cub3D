/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:15:33 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/23 14:59:05 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments", STDERR_FILENO);
		return (1);
	}
	(void)argv;
	// specifications should be a struct that contains all the information
	// specifications = parse(argv[1]);
	
	// Future version of the run_game call
	// run_game(specifications);
	run_game();
}
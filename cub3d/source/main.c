/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:15:33 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/23 15:44:07 by oaydemir         ###   ########.fr       */
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
	specifications = fake_parse();
	run_game(specifications);
	(void)argv;
}

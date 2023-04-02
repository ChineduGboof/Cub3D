/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:15:33 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/02 04:16:08 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_specifications	specifications;

	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	validate_argument(argv[1]);
	if (is_empty_file(argv[1]))
	{
		ft_putstr_fd("Error: map is empty\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	parsing(argv[1], &specifications);
	run_game(specifications);
	return (0);
}

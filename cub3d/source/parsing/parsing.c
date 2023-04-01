/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:56:50 by cegbulef          #+#    #+#             */
/*   Updated: 2023/04/02 00:09:49 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../game/image/image.h"

void	init_specifications(t_specifications *specifications)
{
	ft_memset(specifications, 0, sizeof(t_specifications));
	specifications->floor_color.red = 256;
	specifications->ceiling_color.red = 256;
	specifications->floor_color.green = 256;
	specifications->ceiling_color.green = 256;
	specifications->floor_color.blue = 256;
	specifications->ceiling_color.blue = 256;
}

void	parsing(char *argv, t_specifications *specifications)
{
	init_specifications(specifications);
	parse_colors(argv, specifications);
	parse_textures(argv, specifications);
	parse_map(argv, specifications);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:40:24 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/23 21:55:30 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <unistd.h>
# include <fcntl.h>
# include "game/image/image.h" // for t_color

// We should adjust the window size
// according to the Macs at campus
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500


// The struct that the parser should return
typedef struct s_specifications
{
	char	**map;
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*sprite_texture;
	t_color	floor_color;
	t_color	ceiling_color;
}	t_specifications;

void	run_game(t_specifications specifications);

/**************$ error_checks $*******************/
void	validate_map_file(const char *file);
void	check_map_file_ext(char *file);

#endif
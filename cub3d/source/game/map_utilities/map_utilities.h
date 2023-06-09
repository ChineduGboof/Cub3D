/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:01:43 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 23:08:26 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILITIES_H
# define MAP_UTILITIES_H

# include "../game.h"

t_vector	get_player_position(char **map);
t_vector	get_player_direction(char **map);
t_vector	determine_plane(char **map);

int			**convert_map(char **map);
size_t		get_int_map_height(int **map);
size_t		get_int_map_row_width(int *row);
size_t		get_map_row_width(char *row);

#endif
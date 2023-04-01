/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:01:43 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 18:03:23 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_UTILITIES_H
# define MAP_UTILITIES_H

# include "../game.h"

int			**convert_map(char **map);
t_vector	get_player_position(char **map);
t_vector	get_player_direction(char **map);
t_vector	determine_plane(char **map);

#endif
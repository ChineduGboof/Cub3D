/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:34:31 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/26 14:16:34 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include <math.h>
#include "../cub3d.h"
#include "image/image.h"

#define RED (t_color) {255, 0, 0}
#define GREEN (t_color) {0, 255, 0}
#define BLUE (t_color) {0, 0, 255}
#define WHITE (t_color) {255, 255, 255}
#define BLACK (t_color) {0, 0, 0}
#define YELLOW (t_color) {255, 255, 0}
#define PURPLE (t_color) {255, 0, 255}
#define CYAN (t_color) {0, 255, 255}
#define ORANGE (t_color) {255, 165, 0}

typedef struct s_vector
{
	double x;
	double y;
} t_vector;

typedef struct s_step
{
	int x;
	int y;
} t_step;

typedef struct s_ray
{
	t_vector	position;
	t_vector	direction;
} t_ray;

typedef enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	NONE
} t_direction;

typedef struct s_player
{
	t_vector position; 
	t_vector direction;
	t_vector plane; // the 2d raycaster version of camera plane
} t_player;

typedef struct s_game
{
	t_player	player;
	int			**map; // we can change this to char **
	
} t_game;

void	fake_fill_image(t_image *image, t_color color);
void	fill_image(t_image *image, t_game game);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:34:31 by oaydemir          #+#    #+#             */
/*   Updated: 2023/04/01 21:53:48 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <math.h>
# include "../cub3d.h"
# include "image/image.h"
# include "map_utilities/map_utilities.h"
 
# define RED (t_color) {255, 0, 0, 0}
# define GREEN (t_color) {0, 255, 0, 0}
# define BLUE (t_color) {0, 0, 255, 0}
# define WHITE (t_color) {255, 255, 255, 0}
# define BLACK (t_color) {0, 0, 0, 0}
# define GRAY (t_color) {128, 128, 128, 0}
# define YELLOW (t_color) {255, 255, 0, 0}
# define PURPLE (t_color) {255, 0, 255, 0}
# define CYAN (t_color) {0, 255, 255, 0}
# define ORANGE (t_color) {255, 165, 0, 0}

// events for mlx hooks
enum {
	ON_KEYDOWN = 2,
	ON_DESTROY = 17
};

// keycodes
enum {
	KEY_A = 0,
    KEY_S = 1,
    KEY_D = 2,
	KEY_W = 13,
	KEY_ESCAPE = 53,
    KEY_LEFT = 123,
    KEY_RIGHT = 124,
};

enum  {
	NORTH = 10,
	SOUTH = 11,
	EAST = 12,
	WEST = 13,
	NO_DIRECTION = 14
};

enum {
	LEFT,
	RIGHT
};

// paint
void	paint_image(t_image *image, t_color color, int y_start, int y_end);
void	fill_image(t_image *image, t_game game);

// event handlers
int		on_keydown(int keycode, t_game *game);
int		on_destroy(t_game *game);


// vector manipulation
void	rotate_vector(t_vector *vector, double angle);


// textures
bool	load_textures(void *mlx, struct s_textures *s_textures,
	t_specifications specifications);


void	refresh_display(t_game *game);

void	safely_terminate(t_game *game, int error_code);
void	terminate_with_message(t_game *game, char *message, int error_code);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 11:34:31 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/26 21:52:59 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <math.h>
# include "../cub3d.h"
# include "image/image.h"
 
# define RED (t_color) {255, 0, 0}
# define GREEN (t_color) {0, 255, 0}
# define BLUE (t_color) {0, 0, 255}
# define WHITE (t_color) {255, 255, 255}
# define BLACK (t_color) {0, 0, 0}
# define YELLOW (t_color) {255, 255, 0}
# define PURPLE (t_color) {255, 0, 255}
# define CYAN (t_color) {0, 255, 255}
# define ORANGE (t_color) {255, 165, 0}

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

void	paint_image(t_image *image, t_color color);
void	fill_image(t_image *image, t_game game);

/**************$ event_handlers $*******************/
int		on_keydown(int keycode, t_game *game);
int		on_destroy(t_game *game);
/**************$ end of: event_handlers $*******************/

/**************$ vector manipulation $*******************/
void	rotate_vector(t_vector *vector, double angle);
/**************$ end of: vector manipulation $*******************/

# endif
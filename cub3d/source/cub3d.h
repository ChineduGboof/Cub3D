/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaydemir <oaydemir@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:40:24 by oaydemir          #+#    #+#             */
/*   Updated: 2023/03/23 15:00:49 by oaydemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <libft.h>
# include <unistd.h>

// We should adjust the window size 
// according to the Macs at campus
# define WINDOW_WIDTH 500
# define WINDOW_HEIGHT 500

void	run_game(void);

#endif
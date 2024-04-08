/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:53 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/08 16:24:49 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stddef.h>
#include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

/*Simple structure gathering the counts I'll perform on the map*/

typedef struct s_map_cpt
{
	int			player;
	int			exit;
	int			collectible;
	int			lines;
	int			columns;
}				t_map_cpt;

/*Structure containing all the sprites ready for display*/
typedef struct s_sprite
{
	void		*player;
	void		*exit;
	void		*collectible;
	void		*floor;
	void		*wall;
}				t_sprite;

/*This is the main structure which joins all 
the essentials components of the working game*/

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_sprite	sprite;
	char		**map;
	t_pos		position;
	t_map_cpt	counter;
	int			steps;
	int			fd;
}				t_game;

#endif
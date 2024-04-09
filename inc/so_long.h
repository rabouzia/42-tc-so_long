/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:53 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/09 11:11:42 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include "get_next_line.h"
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
	void		*link; // P
	void		*exit; // E
	void		*ruby; // C
	void		*floor; // 0
	void		*wall; // 1
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

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx_data;


int	ft_dstrlen(char **str);
// int	ft_strlen(char *str);
int	is_map_valid(t_game *map);

#endif
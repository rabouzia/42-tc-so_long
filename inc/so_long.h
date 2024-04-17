/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:53 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/17 14:32:31 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <X11/keysym.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MLX_ERROR 1
# define UP	115
# define DOWN 119
# define LEFT 97
# define RIGHT 100


typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_map_cpt
{
	int			player;
	int			exit;
	int			ruby;
	int			lines;
	int			columns;
}				t_map_cpt;

typedef struct s_sprite
{
	void *link;  // P
	void *exit;  // E
	void *ruby;  // C
	void *floor; // 0
	void *wall;  // 1
}				t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_sprite	img;
	char		**map;
	t_pos		pos;
	t_map_cpt	count;
	int			steps;
	int			fd;
}				t_game;

//------------------- mandatory--------------------
int				ft_dstrlen(char **str);
int				is_map_valid(t_game *map);
int	input(int key,t_game *data);

//---------- printing -----------
int				win_create(t_game *data);
int				img_get(t_game *data);
void			put_link(t_game *d);
void			put_img(t_game *data, int i, int j);
void			init_img(t_game *d);
//----------- init_var -----------
int ft_strchr_count(char **str, char c);
void	read_ber(t_game *data, char *ber);
void init_var(t_game *d);

void printtab(char **d);
//------------------- bonus -----------------------

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:53 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/21 20:04:20 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <X11/keysym.h>
# include <limits.h>
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>

# define MLX_ERROR 0
# define UP 115
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

typedef struct s_link
{
	void		*up;
	void		*down;
	void		*left;
	void		*right;
	void		*ruby;
}				way;

typedef struct s_sprite
{
	way link;    // P
	void *exit;  // E
	void *ruby;  // C
	void *floor; // 0
	void *wall;  // 1
	void		*monster;
}				t_sprite;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_sprite	img;
	int			sp;
	char		**map;
	t_pos		pos;
	t_map_cpt	count;
	int			steps;
	char		*step2;
	int			fd;
}				t_game;

//------------------- mandatory--------------------

int				is_map_valid(t_game *map);
int				input(int key, t_game *data);

//---------- parsing ------------

int				is_good(char c, int i, int j, t_game *map);
int				check_path(t_game *game);
void			flood_fill(char **map, int x, int y, t_game *game);
void			mid_check(char **copy, t_game *game);
int				init_init(t_game *data);

//---------- printing -----------

int				win_create(t_game *data);
int				img_get(t_game *data);
void			put_link(t_game *d);
void			put_img(t_game *data, int i, int j);
void			init_img(t_game *d);

//---------- move ---------------

void			exit_l(t_game *d);
void			exit_w(t_game *d);

//----------- init_var -----------

int				read_ber(t_game *data, char *ber);
int				init_var(t_game *d);
int				tab_size(char **tab);
void			quit_esc(t_game *d);
int				quit_click(t_game *d);
int				nb_ligne(char *file);
void			free_img(t_game *d);
void			free_map(char **map);

//------------ libft -------------

int				ft_strchr_count(char **str, char c);
void			ft_putstr_fd(char *s, int fd);
int				ft_dstrlen(char **str);
void			printtab(char **d);
int				ft_strstr(char *str, char *to_find);
void			*ft_calloc(size_t n, size_t s);
//------------------- bonus -----------------------

#endif
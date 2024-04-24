/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:11:21 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/24 15:01:13 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_create(t_game *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (MLX_ERROR);
	data->win = mlx_new_window(data->mlx, data->count.lines,
			data->count.columns, "The Legend Of Zelda");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (MLX_ERROR);
	}
	return (1);
}

int	img_check(t_game *data)
{
	if (!data->img.link.down || !data->img.link.up || !data->img.link.left
		|| !data->img.link.right || !data->img.link.ruby || !data->img.monster
		|| !data->img.exit || !data->img.ruby || !data->img.floor
		|| !data->img.wall)
		return (loop_imgcheck(data));
	return (1);
}

void	put_addr(t_game *m)
{
	m->tab[0] = m->img.link.down;
	m->tab[1] = m->img.link.up;
	m->tab[2] = m->img.link.right;
	m->tab[3] = m->img.link.left;
	m->tab[4] = m->img.link.ruby;
	m->tab[5] = m->img.monster;
	m->tab[6] = m->img.exit;
	m->tab[7] = m->img.ruby;
	m->tab[8] = m->img.floor;
	m->tab[9] = m->img.wall;
	m->tab[10] = NULL;
}

int	img_get(t_game *data)
{
	int	h;
	int	w;

	data->img.link.down = mlx_xpm_file_to_image(data->mlx,
			"./img/link/link_down.xpm", &h, &w);
	data->img.link.up = mlx_xpm_file_to_image(data->mlx,
			"./img/link/link_up.xpm", &h, &w);
	data->img.link.right = mlx_xpm_file_to_image(data->mlx,
			"./img/link/link_right.xpm", &h, &w);
	data->img.link.left = mlx_xpm_file_to_image(data->mlx,
			"./img/link/link_left.xpm", &h, &w);
	data->img.link.ruby = mlx_xpm_file_to_image(data->mlx,
			"./img/link/ruby_grab.xpm", &h, &w);
	data->img.monster = mlx_xpm_file_to_image(data->mlx, "./img/monster.xpm",
			&h, &w);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm", &h, &w);
	data->img.ruby = mlx_xpm_file_to_image(data->mlx, "./img/ruby.xpm", &h, &w);
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &h,
			&w);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &h, &w);
	put_addr(data);
	if (!img_check(data))
		return (0);
	return (1);
}

void	init_img(t_game *d)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			put_img(d, i, j);
			j++;
		}
		i++;
	}
}

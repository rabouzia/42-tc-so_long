/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:11:21 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/19 21:52:14 by rabouzia         ###   ########.fr       */
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
	if (!data->img.wall || !data->img.ruby || !data->img.link.down
		|| !data->img.exit || !data->img.floor || !data->img.link.ruby
		|| !data->img.link.left || !data->img.link.right || !data->img.link.up)
	{
		printf("err\n");
		return (0);
	}
	return (1);
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
	if (!img_check(data))
		return (0);
	return (1);
}

void	put_link(t_game *d)
{
	if (d->sp == 0)
		mlx_put_image_to_window(d->mlx, d->win, d->img.link.down, d->pos.x * 64,
			d->pos.y * 64);
	if (d->sp == 1)
		mlx_put_image_to_window(d->mlx, d->win, d->img.link.up, d->pos.x * 64,
			d->pos.y * 64);
	if (d->sp == 2)
		mlx_put_image_to_window(d->mlx, d->win, d->img.link.left, d->pos.x * 64,
			d->pos.y * 64);
	if (d->sp == 3)
		mlx_put_image_to_window(d->mlx, d->win, d->img.link.right, d->pos.x
			* 64, d->pos.y * 64);
	if (d->sp == 4)
		mlx_put_image_to_window(d->mlx, d->win, d->img.link.ruby, d->pos.x * 64,
			d->pos.y * 64);
}

void	put_img(t_game *d, int i, int j)
{
	if (d->map[i][j] == 'E' && d->count.ruby == 0)
		mlx_put_image_to_window(d->mlx, d->win, d->img.exit, j * 64, i * 64);
	else if (d->map[i][j] == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->img.ruby, j * 64, i * 64);
	else if (d->map[i][j] == '0' || (d->map[i][j] == 'E' && d->count.ruby != 0))
		mlx_put_image_to_window(d->mlx, d->win, d->img.floor, j * 64, i * 64);
	else if (d->map[i][j] == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->img.wall, j * 64, i * 64);
	else if (d->map[i][j] == 'M')
		mlx_put_image_to_window(d->mlx, d->win, d->img.monster, j * 64, i * 64);
	else if (d->map[i][j] == 'P')
	{
		d->pos.x = j;
		d->pos.y = i;
		put_link(d);
	}
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

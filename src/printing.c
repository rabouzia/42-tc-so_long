/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:11:21 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/17 16:33:06 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_create(t_game *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (MLX_ERROR);
	data->win = mlx_new_window(data->mlx, data->count.lines,
			data->count.columns, "The Legend Of Zelda");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (MLX_ERROR);
	}
	return (1);
}

int	img_get(t_game *data)
{
	int	h;
	int	w;

	data->img.link = mlx_xpm_file_to_image(data->mlx, "./img/link.xpm", &h, &w);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm", &h, &w);
	data->img.ruby = mlx_xpm_file_to_image(data->mlx, "./img/ruby.xpm", &h, &w);
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &h,
			&w);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &h, &w);
	if (!data->img.wall || !data->img.ruby || !data->img.link || !data->img.exit
		|| !data->img.floor)
	{
		printf("err\n");
		return (0);
	}
	return (1);
}

void	put_link(t_game *d)
{
	mlx_put_image_to_window(d->mlx, d->win, d->img.link, d->pos.x * 64, d->pos.y
		* 64);
}

void	put_img(t_game *d, int i, int j)
{
	if (d->map[i][j] == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->img.exit, j * 64, i * 64);
	else if (d->map[i][j] == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->img.ruby, j * 64, i * 64);
	else if (d->map[i][j] == '0')
		mlx_put_image_to_window(d->mlx, d->win, d->img.floor, j * 64, i * 64);
	else if (d->map[i][j] == '1')
		mlx_put_image_to_window(d->mlx, d->win, d->img.wall, j * 64, i * 64);
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

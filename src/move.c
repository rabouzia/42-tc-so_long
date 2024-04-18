/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:41:53 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/18 17:31:26 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_check(t_game *d, int i, int j)
{
	if (d->map[i][j] == '0' || d->map[i][j] == 'M' || d->map[i][j] == 'C'
		|| (d->map[i][j] == 'E' && (d->count.ruby == 0)))
	{
		d->pos = (t_pos){.x = j, .y = i};
		if (d->map[i][j] == 'C')
		{
			d->count.ruby--;
			d->sp = 4;
		}
		if (d->map[i][j] == 'E' && (d->count.ruby == 0))
			exit_w(d);
		if (d->map[i][j] == 'M')
			exit_l(d);
		d->map[i][j] = 'P';
		return (1);
	}
	return (0);
}

int	manage_right_left(t_game *d, int bool)
{
	int	i;
	int	j;

	i = d->pos.y;
	j = d->pos.x;
	if (bool)
	{
		if (d->map[i][++j] == '1')
			return (0);
		d->sp = 3;
		if (!move_check(d, i, j))
			return (0);
		d->map[i][--j] = '0';
	}
	else
	{
		if (d->map[i][--j] == '1')
			return (0);
		d->sp = 2;
		if (!move_check(d, i, j))
			return (0);
		d->map[i][++j] = '0';
	}
	return (1);
}

int	manage_up_down(t_game *d, int bool)
{
	int	i;
	int	j;

	i = d->pos.y;
	j = d->pos.x;
	if (bool)
	{
		if (d->map[++i][j] == '1')
			return (0);
		d->sp = 0;
		if (!move_check(d, i, j))
			return (0);
		d->map[i - 1][j] = '0';
	}
	else
	{
		if (d->map[--i][j] == '1')
			return (0);
		d->sp = 1;
		if (!move_check(d, i, j))
			return (0);
		d->map[i + 1][j] = '0';
	}
	return (1);
}

int	input(int key, t_game *data)
{
	int	n;

	n = 0;
	if (key == XK_Escape)
		quit_esc(data);
	if (key == RIGHT)
		n = manage_right_left(data, 1);
	if (key == LEFT)
		n = manage_right_left(data, 0);
	if (key == UP)
		n = manage_up_down(data, 1);
	if (key == DOWN)
		n = manage_up_down(data, 0);
	if (n)
		init_img(data);
	data->steps++;
	mlx_string_put(data->mlx, data->win, 64, 64, 0x00FF00 , ft_);
	printf("%d pas\n",data->steps);
	return (1);
}

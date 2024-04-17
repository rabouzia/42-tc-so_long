/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:41:53 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/17 11:43:38 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void quit_game(t_game *d)
{
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free(d->mlx);
	exit(1);
}

int move_check(t_game *d, int i, int j)
{
	if (d->map[i][j] == '0')
	{
		d->map[i][j] = 'P';
		d->pos.x = j;
		d->pos.y = i;
	}
	if (d->map[i][j] == 'C')
	{
		d->map[i][j] = 'P';
		d->pos.x = j;
		d->pos.y = i;
		d->count.ruby--;
	}
	if (d->map[i][j] == 'E' && (d->count.ruby == 0))
	{
		d->map[i][j] = 'P';
		printf("gg poto");
		quit_game(d);
	}
	
}

int manage_right_left(t_game *d, int bool)
{
	int i;
	int j;
	
	i = d->pos.y;
	j = d->pos.x;
	if (bool)
	{	if (d->map[i][++j] == '1')
			return (0);
		move_check(d, i, j);
		d->map[i][--j] = '0';
	}
	else
	{
		if (d->map[i][--j] == '1')
			return (0);
		move_check(d, i, j);
		d->map[i][++j] = '0';
	}
	return (1);
}

int manage_up_down(t_game *d, int bool)
{
	int i;
	int j;
	
	i = d->pos.y;
	j = d->pos.x;
	if(bool)
	{
		if (d->map[++i][j] == '1')
			return (0);
		move_check(d, i, j);
		d->map[--i][j] = '0';
	}
	else
	{
		if (d->map[--i][j] == '1')
			return (0);
		move_check(d, i, j);
		d->map[++i][j] = '0';
	}
	return (1);
}

int	input(int key,t_game *data)
{
	if (key == XK_Escape)
		quit_game(data);
	if (key == RIGHT)
		manage_right_left(data, 1);
	if (key == LEFT)
		manage_right_left(data, 0);
	if (key == UP)
		manage_up_down(data, 1);
	if (key == DOWN)	
		manage_up_down(data, 0);
	init_img(data);
	return 1;
}
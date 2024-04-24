/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 11:12:20 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/24 15:01:10 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	exit_w(t_game *d)
{
	ft_putstr("gg poto");
	quit_esc(d);
}

void	exit_l(t_game *d)
{
	ft_putstr("tes nul poto");
	quit_esc(d);
}

int	loop_imgcheck(t_game *m)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (m->tab[i])
		{
			mlx_destroy_image(m->mlx, m->tab[i]);
			m->tab[i] = NULL;
		}
		i++;
	}
	return (0);
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
	if (d->map[i][j] == 'E')
		mlx_put_image_to_window(d->mlx, d->win, d->img.exit, j * 64, i * 64);
	else if (d->map[i][j] == 'C')
		mlx_put_image_to_window(d->mlx, d->win, d->img.ruby, j * 64, i * 64);
	else if (d->map[i][j] == '0')
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
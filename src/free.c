/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:21:21 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/18 16:12:51 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_img(t_game *d)
{
	mlx_destroy_image(d->mlx, d->img.link.down);
	mlx_destroy_image(d->mlx, d->img.link.up);
	mlx_destroy_image(d->mlx, d->img.link.left);
	mlx_destroy_image(d->mlx, d->img.link.right);
	mlx_destroy_image(d->mlx, d->img.link.ruby);
	mlx_destroy_image(d->mlx, d->img.ruby);
	mlx_destroy_image(d->mlx, d->img.exit);
	mlx_destroy_image(d->mlx, d->img.floor);
	mlx_destroy_image(d->mlx, d->img.wall);
	mlx_destroy_image(d->mlx, d->img.monster);
}

void	quit_esc(t_game *d)
{
	free_img(d);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		mlx_destroy_display((*d).mlx);
		free((*d).mlx);
	}
	free_map(d->map);
	exit(1);
}
int	quit_click(t_game *d)
{
	free_img(d);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	if (d->mlx)
	{
		mlx_destroy_display((*d).mlx);
		free((*d).mlx);
	}
	free_map(d->map);
	exit(1);
	return (0);
}

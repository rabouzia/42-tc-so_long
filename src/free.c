/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:21:21 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/18 00:41:11 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_img(t_game *d)
{
    free(d->img.link.down);
    free(d->img.link.up);
    free(d->img.link.left);
    free(d->img.link.right);
    free(d->img.link.ruby);
    free(d->img.ruby);
    free(d->img.exit);
    free(d->img.floor);
    free(d->img.wall);
    //free(d->img.monster);
}

void quit_game(t_game *d)
{
	mlx_destroy_window(d->mlx, d->win);
	mlx_destroy_display(d->mlx);
	free_img(d);
	free(d->mlx);
	exit(1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:21:21 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/17 16:32:29 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_img(t_game *d)
{
    free(d->img.link);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:15 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/18 12:25:44 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_img(data);
	free(data->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
		return (0);
	read_ber(&data, av[1]);
	if (!is_map_valid(&data) || !init_var(&data))
		return (0);
	if (win_create(&data) == MLX_ERROR)
		return (0);
	if (!img_get(&data))
		return (0);
	init_img(&data);
	// printtab(data.map);
	mlx_key_hook(data.win, input, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_loop(data.mlx);
}

/*
	TODO Gerer le segfault si on clique sur la croix
	TODO The map must contain 1 exit, at least 1 collectible,
		and 1 starting position to be valid
	TODO Make the player lose when they touch an enemy patrol
	TODO Add some sprite animation
	TODO Display the movement count directly on screen instead of writing it in the shell
*/
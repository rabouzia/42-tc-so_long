/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:15 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/19 18:32:45 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
		return (0);
	if (!read_ber(&data, av[1]))
		return (0);
	if (!is_map_valid(&data) || !init_var(&data))
		return (0);
	if (!win_create(&data) || !img_get(&data))
		return (0);
	init_img(&data);
	mlx_key_hook(data.win, input, &data);
	mlx_hook(data.win, 17, 0, quit_click, &data);
	mlx_loop(data.mlx);
}

/*
	TODO Gerer les leaks
	TODO floodfill
*/
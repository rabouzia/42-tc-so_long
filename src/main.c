/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:15 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/17 14:51:18 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void printtab(char **d)
{
	int	i;
	i = 0;
	while (d[i])
	{
		printf("%s",d[i]);
		i++;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_game		data;

	if (ac != 2)
		return (0);
	init_var(&data);
	read_ber(&data, av[1]);
	// if (!is_map_valid(&data))
	// 		return (0);
	win_create(&data);
	img_get(&data);
	init_img(&data);
	// printtab(data.map);
	mlx_key_hook(data.win, input, &data);
	mlx_loop(data.mlx);
}

/*
	TODO resize the sprites
	TODO correct the color border of sprites
*/
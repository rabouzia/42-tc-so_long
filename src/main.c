/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:15 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/17 16:42:10 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printtab(char **d)
{
	int	i;

	i = 0;
	while (d[i])
	{
		printf("%s", d[i]);
		i++;
	}
	printf("\n");
}

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_strlen(tab[i]);
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
		return (0);
	read_ber(&data, av[1]);
	init_var(&data);
	if (!is_map_valid(&data))
		return (0);
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
	TODO Clicking on the cross on the window’s frame must close the window and quit the program in a clean way
	TODO The map must contain 1 exit, at least 1 collectible,
		and 1 starting position to be valid
	TODO Make the player lose when they touch an enemy patrol
	TODO Add some sprite animation
	TODO Display the movement count directly on screen instead of writing it in the shell
*/
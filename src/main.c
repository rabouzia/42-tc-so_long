/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:15 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/18 13:08:11 by rabouzia         ###   ########.fr       */
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
	if (!src/printing.c
cc -Wall -Wextra   -lXext -lX11 -Lminilibx-linux/ -lmlx obj/main.o obj/parsing.o obj/printing.o obj/init_var.o obj/move.o obj/free.o obj/get_next_line_utils.o obj/get_next_line.o obj/libft.o obj/miscellaneous.o minilibx-linux/libmlx_Linux.a -o so_long
➜  42-tc-so_long git:(main) ✗ mkae
zsh: command not found: mkae
win_create(&data))
		return (0);
	if (!img_get(&data))
		return (0);
	init_img(&data);

	mlx_key_hook(data.win, input, &data);
	mlx_hook(data.win, 17, 0, close_win, &data);
	mlx_loop(data.mlx);
}

/*
	TODO Gerer le segfault si 
		- on clique sur la croix
		- si une map exite pas
		- map vide
	TODO Gerer les leaks
*/
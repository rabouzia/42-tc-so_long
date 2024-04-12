/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:15 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/12 20:09:51 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	handle_input(int keysym, t_mlx_data *data)
{
	// Check the #defines
	// find / -name keysym.h 2>/dev/null
	// find / -name keysymdef.h 2>/dev/null
	// 119 W
	// 97  A
	// 115 S
	// 100 D
	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

void	read_ber(t_game *map, char *ber)
{
	int	fd;
	int	i;

	fd = open(ber, O_RDONLY, 0664);
	i = 0;
	map->map = malloc(1000);
	while (1)
	{
		map->map[i] = ft_strdup(get_next_line(fd));
		if (map->map[i] == NULL)
			break ;
		i++;
	}
	map->count.lines = 64 * (ft_strlen(map->map[0]) - 1);
	map->count.columns = 64 * ft_dstrlen(map->map);
}

void check_path()
{
	// regarde si ya un mur -> je fais pas le mouvement
	// regarde si ya la sortie -> je verifie si jai tous les rubis
	// regarde si ya un ruby -> je le recupere donc j'ajoute au compteur
	// regarde si ya un rien -> j'avance tranquille
}

// void manage_l_r(t_game *d, int key)
// {// a et d
// 	if (key == RIGHT)
// 	{
// 		// check_path si ya un mur;
// 		// si check_path bouger link et re init sa pos
// 	}
	
// 	if (key == RIGHT)

// }

int	main(int ac, char **av)
{
	t_game		data;
	// t_sprite	img;
	// t_map_cpt	map;
	// t_pos		pos;
	// t_c			c;

	if (ac != 2)
		return (0);
	read_ber(&data, av[1]);
	// if (!is_map_valid(&data))
	// {
	// 	// perror("parsing err");
	// 	return (0);
	// }
	// printf("x = %d\n y = %d\n", pos.x, pos.y);
	win_create(&data);
	img_get(&data);
	// search_pos(&data, &pos, 'P');
	mlx_key_hook(data.win, handle_input, &data);
	init_img(&data);
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
}

/*
	TODO resize the sprites
	TODO correct the color border of sprites
*/
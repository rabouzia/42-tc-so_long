/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:15 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/15 21:32:57 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



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

// void check_path(t_game *d, int i, int j)
// {
// 	// regarde si ya un mur -> je fais pas le mouvement
// 	// regarde si ya la sortie -> je verifie si jai tous les rubis
// 	// regarde si ya un ruby -> je le recupere donc j'ajoute au compteur
// 	// regarde si ya un rien -> j'avance tranquille
	

// }

void printtab(char **d)
{
	int	i;
	int	j;

	i = 0;
	while (d[i])
	{
		printf("%s\n",d[i]);
		i++;
	}
}


int manage_l_r(int key, t_game *d)
{	// a et d
	// check_path si ya un mur;
	// si check_path bouger link et re init sa pos
	int i;
	int j;
	
	i = d->pos.y;
	j = d->pos.x;
	if (key == RIGHT && d->map[i][j + 1] == '0')
	{
			d->pos.x += 1;
			d->map[i][j+1] = 'P';
			put_link(d);
			// j--;
			d->map[i][j] = '0';
			printtab(d->map);
			// printf("the current char is %c\n",d->map[i][j]);
			// printf("link pos are x = %d, y = %d\n",d->pos.x,d->pos.y);
			put_img(d, j, i);
	}
	printf("The %d key has been pressed\n\n", key);
	return 1;
}

int	input(int key,t_game *data)
{
	// Check the #defines
	// find / -name keysym.h 2>/dev/null
	// find / -name keysymdef.h 2>/dev/null
	if (key == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", key);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		exit(1);
	}
	manage_l_r(key, data);
	// printf("The %d key has been pressed\n\n", key);
	return 1;
}

void init_var(t_game *d)
{
	d->count.ruby = 0;
	d->count.columns = 0;
	d->count.exit = 0;
	d->count.player = 0;
	d->count.lines = 0;
	d->pos.x = 0;
	d->pos.y = 0;
	d->steps = 0;
	d->fd = 0;
	
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
	printtab(data.map);
	mlx_key_hook(data.win, input, &data);
	mlx_loop(data.mlx);
}

/*
	TODO resize the sprites
	TODO correct the color border of sprites
*/
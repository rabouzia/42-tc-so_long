/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:15 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/11 14:36:11 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define MLX_ERROR 1



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
int img_init(t_sprite *img, t_game *data)
{
	int h ;
	int w ;
	img->link = mlx_xpm_file_to_image(data->mlx, "./img/link.xpm", &h, &w);
	img->exit = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm", &h, &w);
	img->ruby = mlx_xpm_file_to_image(data->mlx, "./img/ruby.xpm", &h, &w);	
	img->floor = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &h, &w);
	img->wall = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &h, &w);
	if (!img->wall || !img->ruby || !img->link || !img->exit || !img->floor)
	{
		printf("err\n");
		return (0);
	}
	return 1;
}

void read_line(t_game *data, t_sprite *img)
{
	int i, j;
	i = j = 0;
	
    while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			
			if (data->map[i][j] == 'P')	
				mlx_put_image_to_window(data->mlx, data->win, img->link, j * 64, i * 64 );
			else if (data->map[i][j] == 'E')	
				mlx_put_image_to_window(data->mlx, data->win, img->exit, j * 64, i * 64);
			else if (data->map[i][j] == 'C')	
				mlx_put_image_to_window(data->mlx, data->win, img->ruby, j * 64, i * 64);
			else if (data->map[i][j] == '0')	
				mlx_put_image_to_window(data->mlx, data->win, img->floor, j * 64, i * 64);
			else if (data->map[i][j] == '1')	
				mlx_put_image_to_window(data->mlx, data->win, img->wall, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

int win_create(t_game *data, t_map_cpt *map)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (MLX_ERROR);
	data->win = mlx_new_window(data->mlx, map->columns , map->lines,"The Legend Of Zelda");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (MLX_ERROR);
	}
	return 1;
}

// void init_move(t_game *m, t_sprite *link, t_pos *pos)
// {
// 	if ()
// }

void	read_ber(t_game *map, t_map_cpt *s , char *ber)
{
	int fd;
	int i;
	fd = open(ber , O_RDONLY, 0664);
	i = 0;
	while (1)
	{
		map->map[i] = ft_strdup(get_next_line(fd));
		if (map->map[i] == NULL)
            break;
		i++;
	}
	s->lines = 64 * (ft_strlen(map->map[0]) - 1);
	s->columns = 64 * ft_dstrlen(map->map);
}

int main(int ac, char **av)
{
	t_game data;
	t_sprite img;
	t_map_cpt map;
	// t_pos  	pos;
	
	
	if (ac != 2)
		return 0;
	read_ber(&data, &map, av[1]);
	
	// if (!is_map_valid(&data))
	// {
	// 	// perror("parsing err");
	// 	return 0;
	// }
	win_create(&data, &map);
	img_init(&img, &data);
	read_line(&data, &img);

	
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
}
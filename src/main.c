/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:15 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/09 08:25:02 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define MLX_ERROR 1
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 640

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx_data;

int	handle_input(int keysym, t_mlx_data *data)
{
	// Check the #defines
	// find / -name keysym.h 2>/dev/null
	// find / -name keysymdef.h 2>/dev/null
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
// void map_init(t_game *data, t_sprite *img)
// {
	
// }
void read_line(t_game *data, t_sprite *img, char *str)
{
	int i;
	// int j;
	// t_map_cpt *n;
	// char	*str[] = {/*"1111111111111",*/ "10010000000C1", "1000011111001",
	// 		"1P0011E000001",NULL};
	i = 0;
    while (str[i])
	{
			if (str[i] == 'C')	
				mlx_put_image_to_window(data->mlx, data->win, img->link, i * 64, 0 );
			else if (str[i] == 'E')	
				mlx_put_image_to_window(data->mlx, data->win, img->exit, i * 64, 0);
			else if (str[i] == 'C')	
				mlx_put_image_to_window(data->mlx, data->win, img->ruby, i * 64, 0);
			else if (str[i] == '0')	
				mlx_put_image_to_window(data->mlx, data->win, img->floor, i * 64, 0);
			else if (str[i] == '1')	
				mlx_put_image_to_window(data->mlx, data->win, img->wall, i * 64, 0);
		i++;
	}
}
void loop_img (t_game *data, t_sprite *img)
{
	char	*str[] = {/*"1111111111111",*/ "10010000000C1", "1000011111001",
			"1P0011E000001",NULL};
	int i = 0;
	while (str[i])
	{
		read_line(data, img , str[i]);
		i++;
	}
}

int win_create(t_game *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (MLX_ERROR);
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,"The Legend Of Zelda");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (MLX_ERROR);
	}
	return 1;
}
// char **read_map(void)
// {

		

// }


int main(int ac, char **av)
{
	t_game data;
	t_sprite img;
	(void)av;
	
	if (ac != 1)
		return 0;
	win_create(&data);
	img_init(&img, &data);
	loop_img(&data, &img);
	// int i = -1;
	// while (i++ < 10)
	// 	mlx_put_image_to_window(data.mlx, data.win, img.floor, i * 64, 0);
	
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
}

/*
	! taille de map en fonction de la largeur du mur
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:15 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/09 09:10:47 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define MLX_ERROR 1
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 640

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	ft_dstrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
void read_line(t_game *data, t_sprite *img  )//, char *str)
{
	int i, j;
	char	*str[] = {"1111111111111", "10010000000C1", "1000011111001",
			"1P0011E000001","1111111111111",NULL};
	i = j = 0;
	
    while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
		
			if (str[i][j] == 'P')	
				mlx_put_image_to_window(data->mlx, data->win, img->link, j * 64, i * 64 );
			else if (str[i][j] == 'E')	
				mlx_put_image_to_window(data->mlx, data->win, img->exit, j * 64, i * 64);
			else if (str[i][j] == 'C')	
				mlx_put_image_to_window(data->mlx, data->win, img->ruby, j * 64, i * 64);
			else if (str[i][j] == '0')	
				mlx_put_image_to_window(data->mlx, data->win, img->floor, j * 64, i * 64);
			else if (str[i][j] == '1')	
				mlx_put_image_to_window(data->mlx, data->win, img->wall, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void read_map(void)
{
	

}
int win_create(t_game *data, t_map_cpt *map)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (MLX_ERROR);
	data->win = mlx_new_window(data->mlx, map->lines , map->columns,"The Legend Of Zelda");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return (MLX_ERROR);
	}
	return 1;
}


int main(int ac, char **av)
{
	t_game data;
	t_sprite img;
	t_map_cpt map;
	(void)av;
	if (ac != 1)
		return 0;
	char *str[] = {"1111111111111", "10010000000C1", "1000011111001",
			"1P0011E000001","1111111111111",NULL};

	map.lines= 64 * ft_strlen(str[0]);
	map.columns= 64 * ft_dstrlen(str);
	win_create(&data, &map);
	img_init(&img, &data);
	read_line(&data, &img);




	
	mlx_key_hook(data.win, handle_input, &data);
	mlx_loop(data.mlx);
}
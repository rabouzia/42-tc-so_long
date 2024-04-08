/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 10:33:15 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/08 17:25:02 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define MLX_ERROR 1
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

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

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	mlx_key_hook(data.win_ptr,
//                 handle_input,
//                 &data);
// 	mlx_loop(mlx);
// 	mlx_destroy_display(mlx);
// 	free(mlx);
// }

// void		*mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width,
// 				int *height);

// int	mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,int x,
	// 		int y)
	// {
	// }

	int main(void)
{
	t_game data;
	t_sprite img;
	// t_sprite char;
	int h ;
	int w ;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"My first window!");
	if (data.win == NULL)
	{
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		return (MLX_ERROR);
	}

	img.wall = mlx_xpm_file_to_image(data.mlx, "./img/wall.xpm", &h, &w);
	if (!img.wall)
	{
		printf("err\n");
		return (0);
	}
    int i = -1;
    while(++i <= 10)
	    mlx_put_image_to_window(data.mlx, data.win, img.wall, i * 32, 0);
	mlx_key_hook(data.win, handle_input, &data);

	// Leave the control to the EVENT LOOP
	mlx_loop(data.mlx);
}
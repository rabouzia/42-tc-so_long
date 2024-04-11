/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:59:17 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/09 11:38:12 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
TODO You have to check if there’s a valid path in the map.
 */
int	ft_dstrlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	wall_check_up_down(t_game *m)
{
	int	i;
	int	len_y;

	len_y = ft_dstrlen(m->map) - 1;
	i = 0;
	while (m->map[0][i])
	{
		if (m->map[0][i] != '1')
			return (0);
		if (m->map[len_y][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	wall_check_side(t_game *m)
{
	int	i;
	int	len_x;

	i = 0;
	len_x = ft_strlen(m->map[0]);
	while (m->map[i] != NULL)
	{
		if (m->map[i][len_x - 1] != '1')
			return (0);
		if (m->map[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	character_checker(t_game *m)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (m->map[i][j])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (m->map[i][j] == '0' || m->map[i][j] == '1' || m->map[i][j] == 'C')
				j++;
			else if (m->map[i][j] == 'E' || m->map[i][j] == 'P')
				j++;
			else
			{
				printf("%c = ?\n", m->map[i][j]);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	size_checking(t_game *m)
{
	int	x;
	int	y;
	int	res;
	int	i;
	x = ft_strlen(m->map[0]);
	y = ft_dstrlen(m->map);
	
	res = 0;
	i = 0;
	while (m->map[i] != NULL)
	{
		res += ft_strlen(m->map[i]);
		i++;
	}
	if (res == x * y)
		return (1);
	else
		return (0);
}

int	is_map_valid(t_game *m)
{
	if (!m->map)
		return 0;
	if (!size_checking(m))
	{
		perror("size");
		return (0);
	}
	if (!character_checker(m))
	{
		perror("character");
		return (0);
	}
	if (!wall_check_up_down(m))
	{
		perror ("wall up down");
		return (0);
	}
	if (!wall_check_side(m))
	{
		perror("wall side");
		return (0);
	}
	// if (!path_checking)
	// 	return (0);
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
	
// 	char	*str[] = {"1111111111111", "1000000000001", "1000000000001",
// 			"1000000000001", "1000000000001", "1000000000001", "1111111111111",
// 			NULL};

// 	printf("tab ? =  %d\n", size_checking(str));
// }

// void	flood_fill(char ***map, int x, int y, t_game *game)
// {
// 	if (x >= game->counter.lines || x < 0 || y >= game->counter.columns || y < 0)
// 		return ;
// 	if ((*map)[x][y] == '1')
// 		return ;
// 	(*map)[x][y] = '1';
// 	flood_fill(map, x + 1, y, game);
// 	flood_fill(map, x, y + 1, game);
// 	flood_fill(map, x - 1, y, game);
// 	flood_fill(map, x, y - 1, game);
// }

// // int path_checking(t_game *m)
// // {

// // }


// static int    find_path_exit(char **matrix, int i, int j, char from)
// {
//     int    find;

//     find = 0;
//     matrix[i][j] = '*';
//     if (matrix[i][j + 1] == 'E')
//         return (1);
//     if (matrix[i][j - 1] == 'E')
//         return (1);
//     if (matrix[i + 1][j] == 'E')
//         return (1);
//     if (matrix[i - 1][j] == 'E')
//         return (1);
//     if (ft_strchr("0C", matrix[i][j + 1]) && from != 'R')
//         find += find_path_exit(matrix, i, j + 1, 'L');
//     if (ft_strchr("0C", matrix[i][j - 1]) && from != 'L')
//         find += find_path_exit(matrix, i, j - 1, 'R');
//     if (ft_strchr("0C", matrix[i + 1][j]) && from != 'B')
//         find += find_path_exit(matrix, i + 1, j, 'T');
//     if (ft_strchr("0C", matrix[i - 1][j]) && from != 'T')
//         find += find_path_exit(matrix, i - 1, j, 'B');
//     return (find);
// }

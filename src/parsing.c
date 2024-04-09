/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:59:17 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/09 08:51:00 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"
/*
TODO map in .ber
TODO You have to check if there’s a valid path in the map.
 */
#include <stdlib.h>


int	wall_check_up_down(char **str)
{
	int	i;
	int	len_y;

	len_y = ft_dstrlen(str) - 1;
	i = 0;
	while (str[0][i])
	{
		if (str[0][i] != '1')
			return (0);
		if (str[len_y][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	wall_check_side(char **str)
{
	int	i;
	int	j;
	int	len_x;

	i = 0;
	len_x = ft_strlen(str[0]);
	while (str[i] != NULL)
	{
		if (str[i][len_x - 1] != '1')
			return (0);
		if (str[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	character_checker(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i][j])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0' || str[i][j] == '1' || str[i][j] == 'C')
				j++;
			if (str[i][j] == 'E' || str[i][j] == 'P')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	size_checking(char **str)
{
	int	x;
	int	y;
	int	res;
	int	i;

	x = ft_strlen(str[0]);
	y = ft_dstrlen(str);
	i = 0;
	while (str[i] != NULL)
	{
		res += ft_strlen(str[i]);
		i++;
	}
	if (res == x * y)
		return (1);
	else
		return (0);
}

int	is_map_valid(char **str)
{
	if (!str || !*str)
		return 0;
	if (!size_checking)
		return (0);
	if (!character_checker)
		return (0);
	if (!wall_check_up_down)
		return (0);
	if (!wall_check_side)
		return (0);
	// if (!path_checking)
	// 	return (0);
	return (1);
}

#include <stdio.h>

int	main(void)
{
	
	char	*str[] = {"1111111111111", "1000000000001", "1000000000001",
			"1000000000001", "1000000000001", "1000000000001", "1111111111111",
			NULL};

	printf("tab ? =  %d\n", size_checking(str));
}

void	flood_fill(char ***map, int x, int y, t_game *game)
{
	if (x >= game->counter.lines || x < 0 || y >= game->counter.columns || y < 0)
		return ;
	if ((*map)[x][y] == '1')
		return ;
	(*map)[x][y] = '1';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y - 1, game);
}

// int path_checking(char **str)
// {

// }


static int    find_path_exit(char **matrix, int i, int j, char from)
{
    int    find;

    find = 0;
    matrix[i][j] = '*';
    if (matrix[i][j + 1] == 'E')
        return (1);
    if (matrix[i][j - 1] == 'E')
        return (1);
    if (matrix[i + 1][j] == 'E')
        return (1);
    if (matrix[i - 1][j] == 'E')
        return (1);
    if (ft_strchr("0C", matrix[i][j + 1]) && from != 'R')
        find += find_path_exit(matrix, i, j + 1, 'L');
    if (ft_strchr("0C", matrix[i][j - 1]) && from != 'L')
        find += find_path_exit(matrix, i, j - 1, 'R');
    if (ft_strchr("0C", matrix[i + 1][j]) && from != 'B')
        find += find_path_exit(matrix, i + 1, j, 'T');
    if (ft_strchr("0C", matrix[i - 1][j]) && from != 'T')
        find += find_path_exit(matrix, i - 1, j, 'B');
    return (find);
}

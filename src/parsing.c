/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:59:17 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/17 17:24:53 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
TODO You have to check if there’s a valid path in the map.
 */

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

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

int	is_good(char c)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == 'P')
		return (1);
	if (c == 'C')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'M')
		return (1);
	return (0);
}

int	character_checker(t_game *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (!is_good(m->map[i][j]))
				return (0);
			j++;
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
		if (x != ft_strlen(m->map[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_map_valid(t_game *m)
{
	if (!m->map)
		return(ft_putstr_fd("Error\nnothing to do here", 1),0);
	if (!size_checking(m))
		return(ft_putstr_fd("Error\nwrong size", 1),0);
	if (!character_checker(m))
		return(ft_putstr_fd("Error\nwrong char", 1),0);
	if (!wall_check_up_down(m))
		return(ft_putstr_fd("Error\nwrong char up and down", 1),0);
	if (!wall_check_side(m))
		return(ft_putstr_fd("Error\nwrong side char", 1), 0);
	// if (!path_checking)
	// 	return (0);
	return (1);
}

void	flood_fill(char ***map, int x, int y, t_game *game)
{
	if (x >= game->count.lines || x < 0 || y >= game->count.columns
|| y < 0)
		return ;
	if ((*map)[x][y] == '1')
		return ;
	(*map)[x][y] = '1';
	flood_fill(map, x + 1, y, game);
	flood_fill(map, x, y + 1, game);
	flood_fill(map, x - 1, y, game);
	flood_fill(map, x, y - 1, game);
}

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

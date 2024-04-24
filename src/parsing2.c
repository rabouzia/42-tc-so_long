/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:23:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/24 13:59:51 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_good(char c, int i, int j, t_game *data)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == 'P')
	{
		data->pos.x = i;
		data->pos.y = j;
		return (1);
	}
	if (c == 'C')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'M')
		return (1);
	return (0);
}

char	**ft_copy(char **map, t_game *game)
{
	char	**copied;
	int		i;
	int		len;

	i = 0;
	copied = ft_calloc(sizeof(char *), tab_size(map) + 1);
	if (!copied)
	{
		free_map(copied);
		quit_esc(game);
		return (NULL);
	}
	len = tab_size(map);
	while (i < len)
	{
		copied[i] = ft_strdup(map[i]);
		i++;
	}
	copied[i] = NULL;
	return (copied);
}

int	check_path(t_game *data)
{
	char	**copy;
	int		i;
	int		j;
	int		h;

	h = data->count.lines;
	copy = ft_copy(data->map, data);
	flood_fill(copy, data->pos.x, data->pos.y, data);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (!ft_strchr("01M", copy[i][j]))
			{
				free_map(copy);
				return (0);
			}
			j++;
		}
		i++;
	}
	free_map(copy);
	return (1);
}

void	flood_fill(char **map, int x, int y, t_game *m)
{
	if (x >= m->count.lines || x < 0 || y >= m->count.columns || y < 0)
		return ;
	if (map[x][y] == '1' || map[x][y] == 'M')
		return ;
	if (map[x][y] == 'E')
	{
		map[x][y] = '1';
		return ;
	}
	map[x][y] = '1';
	flood_fill(map, x + 1, y, m);
	flood_fill(map, x, y + 1, m);
	flood_fill(map, x - 1, y, m);
	flood_fill(map, x, y - 1, m);
}

int	init_init(t_game *data)
{
	data->count.ruby = ft_strchr_count(data->map, 'C');
	data->count.lines = 64 * (ft_strlen(data->map[0]));
	data->count.columns = 64 * ft_dstrlen(data->map);
	data->count.exit = ft_strchr_count(data->map, 'E');
	data->count.player = ft_strchr_count(data->map, 'P');
	if (data->count.exit != 1 || data->count.player != 1
		|| data->count.ruby < 1)
		return (return_map_error("Error\n C, P or M\n", data), 0);
	return (1);
}

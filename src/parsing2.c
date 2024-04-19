/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:23:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/19 22:10:25 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	mid_check(char **copy, t_game *m)
{
	int	i;
	int	j;

	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] != '0' && copy[i][j] != '1')
			{
				free_map(copy);
				close(m->fd);
				quit_esc(m);
			}
			j++;
		}
		i++;
	}
}

int	check_path(t_game *m)
{
	flood_fill(&m->map, m->pos.x, m->pos.y, m);
	mid_check(m->map, m);
	return (1);
}

void	flood_fill(char ***map, int x, int y, t_game *m)
{
	if (x >= m->count.lines || x < 0 || y >= m->count.columns || y < 0)
		return ;
	if ((*map)[x][y] == '1')
		return ;
	(*map)[x][y] = '1';
	flood_fill(map, x + 1, y, m);
	flood_fill(map, x, y + 1, m);
	flood_fill(map, x - 1, y, m);
	flood_fill(map, x, y - 1, m);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:23:18 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/18 16:58:13 by rabouzia         ###   ########.fr       */
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


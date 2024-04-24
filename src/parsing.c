/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:59:17 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/24 15:57:35 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	i = 0;
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			if (!is_good(m->map[i][j], i, j, m))
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
	int	i;

	x = ft_strlen(m->map[0]);
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
	if (!m->map || !(*m->map))
		return (return_map_error("Error\n Empty map\n", m), 0);
	if ((m->count.lines / 64 < 5) && m->count.columns / 64 < 5)
		return (return_map_error("Error\n Too small\n", m), 0);
	if ((m->count.lines  / 64 > 21) && m->count.columns  / 64 > 40)
		return (return_map_error("Error\n Too BIG\n", m), 0);
	if (!size_checking(m))
		return (return_map_error("Error\nWrong size\n", m), 0);
	if (!character_checker(m))
		return (return_map_error("Error\nWrong char\n", m), 0);
	if (!wall_check_up_down(m))
		return (return_map_error("Error\nWrong char up and down\n", m), 0);
	if (!wall_check_side(m))
		return (return_map_error("Error\nWrong side char\n", m), 0);
	if (!check_path(m))
		return (return_map_error("Error\nNo way bro o_o\n", m));
	return (1);
}

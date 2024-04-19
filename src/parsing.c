/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:59:17 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/18 18:43:49 by ramzerk          ###   ########.fr       */
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
	{
		free(m->map);
		return (ft_putstr_fd("Error\n Empty map", 1), 0);
	}
	if (!size_checking(m)) // leak
		return (ft_putstr_fd("Error\nWrong size", 1), 0);
	if (!character_checker(m)) // leak
		return (ft_putstr_fd("Error\nWrong char", 1), 0);
	if (!wall_check_up_down(m)) // leak
		return (ft_putstr_fd("Error\nWrong char up and down", 1), 0);
	if (!wall_check_side(m)) // leak
		return (ft_putstr_fd("Error\nWrong side char", 1), 0);
	// if (!check_path(m))
	// 	return (ft_putstr_fd("Error\nNo way bro o_o", 1), 0);
	return (1);
}

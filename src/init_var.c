/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:05:14 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/18 17:25:59 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_var(t_game *d)
{
	d->pos.x = 0;
	d->pos.y = 0;
	d->steps = -1;
	d->fd = 0;
	d->sp = 0;
	d->count.ruby = ft_strchr_count(d->map, 'C');
	d->count.lines = 64 * (ft_strlen(d->map[0]));
	d->count.columns = 64 * ft_dstrlen(d->map);
	d->count.exit = ft_strchr_count(d->map, 'E');
	d->count.player = ft_strchr_count(d->map, 'P');
	if (d->count.exit != 1 || d->count.player != 1)
		return (ft_putstr_fd("Error\n Not enough or Too much E or P\n", 1), 0);
	return (1);
}
int	check_extension(char *ber)
{
	if (ft_strstr(ber, ".ber"))
		return (0);
	return (1);
}

int	read_ber(t_game *data, char *ber)
{
	int		i;
	char	*line;

	if (!check_extension(ber))
		return (ft_putstr_fd("Error\nWrong file extension", 1), 0);
	i = 0;
	data->fd = open(ber, O_RDONLY, 0664);
	data->map = malloc(1000 * sizeof(char *));
	while (1)
	{
		line = get_next_line(data->fd);
		data->map[i] = ft_strdup(line);
		free(line);
		if (!data->map[i])
			break ;
		i++;
	}
	return (1);
}

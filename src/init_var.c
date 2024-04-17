/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:05:14 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/17 16:20:12 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_var(t_game *d)
{
	d->count.exit = 0;
	d->count.player = 0;
	d->pos.x = 0;
	d->pos.y = 0;
	d->steps = 0;
	d->fd = 0;
	d->count.ruby = ft_strchr_count(d->map, 'C');
	d->count.lines = 64 * (ft_strlen(d->map[0]));
	d->count.columns = 64 * ft_dstrlen(d->map);
}

int	ft_strchr_count(char **str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == c)
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

void	read_ber(t_game *data, char *ber)
{
	int		i;
	char	*line;

	i = 0;
	data->fd = open(ber, O_RDONLY, 0664);
	data->map = malloc(100);
	while (1)
	{
		line = get_next_line(data->fd);
		data->map[i] = ft_strdup(line);
		free(line);
		if (!data->map[i])
			break ;
		i++;
	}
}

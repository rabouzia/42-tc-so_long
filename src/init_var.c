/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramzerk <ramzerk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:05:14 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/17 15:04:18 by ramzerk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_var(t_game *d)
{
	d->count.ruby = 0;
	d->count.columns = 0;
	d->count.exit = 0;
	d->count.player = 0;
	d->count.lines = 0;
	d->pos.x = 0;
	d->pos.y = 0;
	d->steps = 0;
	d->fd = 0;	
}

int ft_strchr_count(char **str, char c)
{
	int i;
	int j;
	int k;
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
	return k;
}



void	read_ber(t_game *data, char *ber)
{
	int	fd;
	int	i;
	fd = open(ber, O_RDONLY, 0664);
	i = 0;
	data->map = malloc(1000);
	while (1)
	{
		data->map[i] = ft_strdup(get_next_line(fd));
		if (data->map[i] == NULL)
			break ;
		i++;
	}
	data->count.ruby = ft_strchr_count(data->map, 'C');
	data->count.lines = 64 * (ft_strlen(data->map[0]) - 1);
	data->count.columns = 64 * ft_dstrlen(data->map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:05:14 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/24 14:58:39 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_var(t_game *d)
{
	d->pos.x = 0;
	d->pos.y = 0;
	d->steps = 0;
	d->fd = 0;
	d->sp = 0;
	d->mlx = NULL;
	return (1);
}

int	check_extension(char *ber)
{
	if (ft_strstr(ber, ".ber"))
		return (0);
	return (1);
}

int	nb_ligne(char *file)
{
	int		fd;
	int		i;
	char	*ligne;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while (1)
	{
		ligne = get_next_line(fd);
		if (!ligne)
			break ;
		free(ligne);
		i++;
	}
	close(fd);
	return (i);
}

int	read_ber(t_game *data, char *ber)
{
	int		i;
	int		j;
	char	*line;

	if (!check_extension(ber))
		return (ft_putstr_fd("Error\nWrong file extension", 1), 0);
	i = 0;
	j = nb_ligne(ber);
	data->fd = open(ber, O_RDONLY, 0664);
	data->map = ft_calloc(j + 1, sizeof(char *));
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			break ;
		free(line);
		i++;
	}
	if (!init_init(data))
		return (0);
	return (1);
}

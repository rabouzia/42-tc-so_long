/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:41:53 by ramzerk           #+#    #+#             */
/*   Updated: 2024/04/24 15:05:39 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_check(t_game *d, int i, int j)
{
	if (d->map[i][j] == '0' || d->map[i][j] == 'M' || d->map[i][j] == 'C'
		|| (d->map[i][j] == 'E' && (d->count.ruby == 0)))
	{
		d->pos = (t_pos){.x = j, .y = i};
		if (d->map[i][j] == 'C')
		{
			d->count.ruby--;
			d->sp = 4;
		}
		if (d->map[i][j] == 'E' && (d->count.ruby == 0))
			exit_w(d);
		if (d->map[i][j] == 'M')
			exit_l(d);
		d->map[i][j] = 'P';
		return (1);
	}
	return (0);
}

int	manage_right_left(t_game *d, int bool)
{
	int	i;
	int	j;

	i = d->pos.y;
	j = d->pos.x;
	if (bool)
	{
		if (d->map[i][++j] == '1')
			return (0);
		d->sp = 3;
		if (!move_check(d, i, j))
			return (0);
		d->map[i][--j] = '0';
	}
	else
	{
		if (d->map[i][--j] == '1')
			return (0);
		d->sp = 2;
		if (!move_check(d, i, j))
			return (0);
		d->map[i][++j] = '0';
	}
	return (1);
}

int	manage_up_down(t_game *d, int bool)
{
	int	i;
	int	j;

	i = d->pos.y;
	j = d->pos.x;
	if (bool)
	{
		if (d->map[++i][j] == '1')
			return (0);
		d->sp = 0;
		if (!move_check(d, i, j))
			return (0);
		d->map[i - 1][j] = '0';
	}
	else
	{
		if (d->map[--i][j] == '1')
			return (0);
		d->sp = 1;
		if (!move_check(d, i, j))
			return (0);
		d->map[i + 1][j] = '0';
	}
	return (1);
}

size_t	ft_strlcpy(char *dest,  char *src, size_t len)
{
	size_t	i;
	size_t	x;

	x = ft_strlen(src);
	i = 0;
	if (len < 1)
		return (x);
	if (len != 0)
	{
		while (src[i] != '\0' && i < len - 1)
		{
			dest[i] = src[i];
			i++;
		}
	}
	dest[i] = '\0';
	return (x);
}

int	getlength(int n)
{
	int	len;

	len = 2;
	if (n < 0)
	{
		if (n == -2147483648)
			return (12);
		len++;
		n *= -1;
	}
	while (n >= 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*return_strlcpy(char *str, char *dat, int len)
{
	ft_strlcpy(str, dat, len);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*sp;
	short	isminus;

	str = (char *)malloc(getlength(n) * sizeof(char));
	if (!str)
		return (NULL);
	sp = str + getlength(n) - 1;
	*sp-- = '\0';
	isminus = 0;
	if (n == -2147483648)
		return (return_strlcpy(str, "-2147483648", 12));
	if (n < 0)
	{
		*str = '-';
		n *= -1;
		isminus = 1;
	}
	while (sp - isminus - str >= 0)
	{
		*sp-- = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}
void	step_counter(t_game *d)
{
	d->step2 = ft_itoa(d->steps);
	if (!mlx_string_put(d->mlx, d->win, 64, 64, 0xFFFFFF, d->step2))
		free(d->step2);
}

int	input(int key, t_game *data)
{
	int	n;

	n = 0;
	if (key == XK_Escape)
		quit_esc(data);
	if (key == RIGHT)
		n = manage_right_left(data, 1);
	if (key == LEFT)
		n = manage_right_left(data, 0);
	if (key == UP)
		n = manage_up_down(data, 1);
	if (key == DOWN)
		n = manage_up_down(data, 0);
	if (n)
		init_img(data);
	data->steps++;
	step_counter(data);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:27:14 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/21 19:40:32 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (0);
		i++;
		j = 0;
	}
	return (1);
}

void	*ft_calloc(size_t n, size_t s)
{
	char	*str;
	size_t	i;

	i = 0;
	if (s != 0)
	{
		if (n > INT_MAX / s)
			return (0);
	}
	str = (char *)malloc(n * s);
	if (str == 0)
		return (0);
	while (i < n * s)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}
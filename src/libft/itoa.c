/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabouzia <rabouzia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:07:43 by rabouzia          #+#    #+#             */
/*   Updated: 2024/04/24 15:16:44 by rabouzia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlcpy(char *dest, char *src, size_t len)
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

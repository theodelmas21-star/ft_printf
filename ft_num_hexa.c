/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:45:53 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/11/17 18:06:49 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	to_hex(int n, char c)
{
	if (n < 10)
	{
		return (n = '0' + n);
	}
	else if (c == 'x')
	{
		return (n = 'a' + n % 10);
	}
	else
		return (n = 'A' + n % 10);
}

static int	calcul_malloc(unsigned long s)
{
	unsigned long	j;
	int				i;

	j = s;
	i = 0;
	while (j)
	{
		j = j / 16;
		i++;
	}
	return (i);
}

static char	*calcul(unsigned long s, char c)
{
	int		low;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = calcul_malloc(s);
	str = malloc(sizeof(char) * j + 1);
	if (!str)
		return (NULL);
	str[j] = '\0';
	while (j != 0)
	{
		low = s % 16;
		s = s / 16;
		str[--j] = to_hex(low, c);
	}
	return (str);
}

void	ft_num_hexa(unsigned int x, int *count, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	if (x == 0)
	{
		ft_putchar_count('0', count);
		return ;
	}
	str = calcul(x, c);
	if (!str)
	{
		return ;
	}
	while (str[i])
		ft_putchar_count(str[i++], count);
	free(str);
}

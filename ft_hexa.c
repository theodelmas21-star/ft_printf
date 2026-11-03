/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 18:08:43 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/11/17 17:54:01 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	to_hex(int n)
{
	if (n < 10)
	{
		return (n = '0' + n);
	}
	else
	{
		return (n = 'a' + n % 10);
	}
}

int	calcul_malloc(unsigned long s)
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

static char	*calcul(unsigned long s)
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
		str[--j] = to_hex(low);
	}
	return (str);
}

void	ft_hexa(void *s, int *count)
{
	unsigned long	stri;
	char			*str;
	size_t			i;

	i = 0;
	if (!s)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	stri = (unsigned long int)s;
	str = calcul(stri);
	ft_putchar_count('0', count);
	ft_putchar_count('x', count);
	while (str[i])
		ft_putchar_count(str[i++], count);
	free(str);
}

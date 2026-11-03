/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:02:10 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/11/18 12:16:53 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calcul_malloc(unsigned int s)
{
	unsigned int	j;
	int				i;

	j = s;
	i = 0;
	while (j)
	{
		j = j / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_unsigned(unsigned int n)
{
	unsigned int	i;
	char			*str;
	unsigned int	j;

	i = 0;
	j = calcul_malloc(n);
	str = malloc(sizeof(char) * j + 1);
	if (!str)
		return (NULL);
	str[j] = '\0';
	while (j != i)
	{
		str[--j] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

void	ft_unsigned_decimal(unsigned int res, int *count)
{
	char	*str;
	size_t	i;

	if (res == 0)
	{
		ft_putchar_count('0', count);
		return ;
	}
	str = ft_itoa_unsigned(res);
	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		ft_putchar_count(str[i], count);
		i++;
	}
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:57:26 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/11/19 16:42:53 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *count)
{
	int		i;
	char	str[10];

	i = 0;
	if (n == -2147483648)
		ft_putstr("-2147483648", count);
	if (n == 0)
		ft_putchar_count('0', count);
	if (n < 0 && n != -2147483648 && n != 0)
	{
		n *= -1;
		ft_putchar_count('-', count);
	}
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0 && n != -2147483648)
	{
		ft_putchar_count(str[i], count);
		i--;
	}
}

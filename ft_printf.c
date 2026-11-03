/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:14:24 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/11/19 16:38:37 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_global(int *count, char c, va_list ap)
{
	if (c == '%')
		ft_putchar_count(c, count);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, int), count);
	if (c == 'c')
		ft_putchar_count((char)va_arg(ap, int), count);
	if (c == 's')
		ft_putstr(va_arg(ap, char *), count);
	if (c == 'p')
		ft_hexa(va_arg(ap, void *), count);
	if (c == 'u')
		ft_unsigned_decimal(va_arg(ap, unsigned int), count);
	if (c == 'x' || c == 'X')
		ft_num_hexa(va_arg(ap, int), count, c);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	i;
	int		count;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			ft_printf_global(&count, format[i], ap);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}

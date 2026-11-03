/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:34:59 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/11/19 16:41:31 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
void	ft_putchar_count(char c, int *count);
void	ft_putstr(char *s, int *count);
void	ft_hexa(void *s, int *count);
void	ft_unsigned_decimal(unsigned int res, int *count);
void	ft_num_hexa(unsigned int n, int *count, char c);
void	ft_putnbr(int n, int *count);

#endif
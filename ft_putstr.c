/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:50:49 by tdelmas2          #+#    #+#             */
/*   Updated: 2025/11/17 17:53:16 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (!s)
		ft_putstr("(null)", count);
	else
	{
		while (s[i])
		{
			ft_putchar_count(s[i], count);
			i++;
		}
	}
	return ;
}

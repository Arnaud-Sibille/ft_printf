/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:03:36 by asibille          #+#    #+#             */
/*   Updated: 2022/01/20 18:32:17 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_size_d(size_t u)
{
	int	sizeof_int;

	sizeof_int = 1;
	while (u > 9)
	{
		u /= 10;
		++sizeof_int;
	}
	return (sizeof_int);
}

void	ft_flag_point_d(size_t u, t_conv_flags *fl, int *size)
{
	int	sizeof_int;
	int	diff;

	sizeof_int = ft_size_d(u);
	diff = ((fl ->point) - sizeof_int);
	if (diff > 0)
	{
		while (diff > 0)
		{
			ft_putchar_count('0', 1, size);
			--diff;
		}
	}
}

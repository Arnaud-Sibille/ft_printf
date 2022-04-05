/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_point_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:19:55 by asibille          #+#    #+#             */
/*   Updated: 2022/01/20 18:19:56 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_x(size_t u)
{
	int	sizeof_u;

	sizeof_u = 1;
	while (u > 15)
	{
		u /= 16;
		++sizeof_u;
	}
	return (sizeof_u);
}

void	ft_flag_point_x(size_t u, t_conv_flags *fl, int *size)
{
	int	sizeof_u;
	int	diff;

	sizeof_u = ft_size_x(u);
	diff = ((fl ->point) - sizeof_u);
	if (diff > 0)
	{
		while (diff > 0)
		{
			ft_putchar_count('0', 1, size);
			--diff;
		}
	}
}

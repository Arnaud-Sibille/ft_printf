/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:08:40 by asibille          #+#    #+#             */
/*   Updated: 2022/01/14 17:09:02 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static size_t	ft_find_div(size_t u)
{
	size_t	div;

	div = 10;
	while (u / div)
	{
		div *= 10;
	}
	return (div / 10);
}

static void	ft_putuns_count(size_t u, int fd, int *size)
{
	size_t	div;

	div = ft_find_div(u);
	while (div > 1)
	{
		ft_putchar_count((u / div) + '0', fd, size);
		u %= div;
		div /= 10;
	}
	ft_putchar_count(u + '0', fd, size);
}

void	ft_uns_dec(unsigned int u, t_conv_flags *fl, int *size)
{
	if (!(fl->minus))
		ft_flag_width_d((size_t) u, fl, size, 0);
	ft_flag_point_d((size_t) u, fl, size);
	if ((fl->point) || u || !(fl->ispoint))
		ft_putuns_count((size_t) u, 1, size);
	if (fl->minus)
		ft_flag_width_d((size_t) u, fl, size, 0);
}

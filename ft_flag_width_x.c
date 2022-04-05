/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_width_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:29:50 by asibille          #+#    #+#             */
/*   Updated: 2022/01/20 16:29:52 by asibille         ###   ########.fr       */
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

static void	ft_put_width(int diff, t_conv_flags *fl, int *size)
{
	while (diff > 0)
	{
		if (fl->zero && !(fl->minus) && !(fl->ispoint))
			ft_putchar_count('0', 1, size);
		else
			ft_putchar_count(' ', 1, size);
		--diff;
	}
}

void	ft_flag_width_x(size_t u, t_conv_flags *fl, int *size)
{
	int	sizeof_u;
	int	diff;

	diff = 0;
	if (fl->hashtag)
		diff = -2;
	sizeof_u = ft_size_x(u);
	if (!(fl->point) && !u && (fl->ispoint))
		diff += fl->width;
	else if (fl->point > (sizeof_u))
		diff += (fl->width) - (fl ->point);
	else
		diff += (fl->width) - (sizeof_u);
	ft_put_width(diff, fl, size);
}

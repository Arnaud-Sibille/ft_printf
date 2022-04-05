/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_width_d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:16:28 by asibille          #+#    #+#             */
/*   Updated: 2022/01/19 19:16:30 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_d(unsigned int n)
{
	int	sizeof_int;

	sizeof_int = 1;
	while (n > 9)
	{
		n /= 10;
		++sizeof_int;
	}
	return (sizeof_int);
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

void	ft_flag_width_d(size_t u, t_conv_flags *fl, int *size, int isneg)
{
	int	sizeof_int;
	int	diff;

	if (fl->plus || fl->space)
		isneg = 1;
	sizeof_int = ft_size_d((unsigned int) u);
	if (!(fl->point) && !u && (fl->ispoint))
		diff = fl->width;
	else if (fl->point > (sizeof_int))
		diff = (fl->width) - ((fl ->point) + isneg);
	else
		diff = (fl->width) - (sizeof_int + isneg);
	ft_put_width(diff, fl, size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:53:14 by asibille          #+#    #+#             */
/*   Updated: 2022/01/14 15:53:35 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_int_dec(int n, t_conv_flags *fl, int *size)
{
	long	n2;
	size_t	u;
	int		isneg;

	n2 = (long) n;
	isneg = 0;
	if (n2 < 0)
	{
		n2 = -n2;
		isneg = 1;
	}
	u = (size_t) n2;
	if (fl->zero && !(fl->minus) && !(fl->ispoint))
		ft_flag_plus_space_d(fl, size, isneg);
	if (!fl->minus)
		ft_flag_width_d(u, fl, size, isneg);
	if (!(fl->zero) || fl->minus || fl->ispoint)
		ft_flag_plus_space_d(fl, size, isneg);
	ft_flag_point_d(u, fl, size);
	if ((fl->point) || u || !(fl->ispoint))
		ft_putnbr_count(u, 1, size);
	if (fl->minus)
		ft_flag_width_d(u, fl, size, isneg);
}

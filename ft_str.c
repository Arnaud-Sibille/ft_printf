/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:29:01 by asibille          #+#    #+#             */
/*   Updated: 2022/01/14 15:29:05 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putstrn_count(char *s, int fd, int *size, int n)
{
	while (n > 0)
	{
		ft_putchar_count(*s, fd, size);
		--n;
		++s;
	}
}

void	ft_str(char *s, t_conv_flags *fl, int *size)
{
	if (!s)
		s = "(null)";
	if (!(fl->minus))
		ft_flag_width_s(s, fl, size);
	if ((fl->point) || !(fl->ispoint))
	{
		if (fl->ispoint && (ft_strlen(s) > (size_t)(fl->point)))
			ft_putstrn_count(s, 1, size, fl->point);
		else
			ft_putstr_count(s, 1, size);
	}
	if (fl->minus)
		ft_flag_width_s(s, fl, size);
}

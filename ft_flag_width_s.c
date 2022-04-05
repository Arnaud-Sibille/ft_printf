/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_width_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:41:52 by asibille          #+#    #+#             */
/*   Updated: 2022/01/20 18:41:54 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_width_s(char *s, t_conv_flags *fl, int *size)
{
	int	diff;

	if (!(fl->point) && !s && (fl->ispoint))
		diff = fl->width;
	else
		diff = (fl->width) - ft_strlen(s);
	if (fl->ispoint)
	{
		if ((size_t) fl->point < ft_strlen(s))
			diff = (fl->width) - (fl->point);
	}
	if (diff > 0)
	{
		while (diff)
		{
			ft_putchar_count(' ', 1, size);
			--diff;
		}
	}
}

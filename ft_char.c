/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:30:27 by asibille          #+#    #+#             */
/*   Updated: 2022/01/14 11:30:34 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_char(char c, t_conv_flags *fl, int *size)
{
	if (!(fl->minus))
		ft_flag_width_d((size_t) 1, fl, size, 0);
	ft_putchar_count(c, 1, size);
	if (fl->minus)
		ft_flag_width_d((size_t) 1, fl, size, 0);
}

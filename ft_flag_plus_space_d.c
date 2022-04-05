/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_plus_space_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:56:20 by asibille          #+#    #+#             */
/*   Updated: 2022/01/19 19:56:27 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_plus_space_d(t_conv_flags *fl, int *size, int isneg)
{
	if (isneg)
		ft_putchar_count('-', 1, size);
	else if (fl->plus)
		ft_putchar_count('+', 1, size);
	else if (fl->space)
		ft_putchar_count(' ', 1, size);
}

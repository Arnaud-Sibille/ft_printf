/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:21:51 by asibille          #+#    #+#             */
/*   Updated: 2022/01/14 11:21:53 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_conv(va_list ptr_arg, t_conv_flags *fl, int *size)
{
	if (fl->type == 'c')
		ft_char((char) va_arg(ptr_arg, int), fl, size);
	else if (fl->type == 's')
		ft_str(va_arg(ptr_arg, char *), fl, size);
	else if (fl->type == 'p')
		ft_ptr(va_arg(ptr_arg, void *), fl, size);
	else if (fl->type == 'd')
		ft_int_dec(va_arg(ptr_arg, int), fl, size);
	else if (fl->type == 'i')
		ft_int_dec(va_arg(ptr_arg, int), fl, size);
	else if (fl->type == 'u')
		ft_uns_dec(va_arg(ptr_arg, unsigned int), fl, size);
	else if (fl->type == 'x')
		ft_uns_hexa(va_arg(ptr_arg, unsigned int), fl, size);
	else if (fl->type == 'X')
		ft_uns_hexa_maj(va_arg(ptr_arg, unsigned int), fl, size);
	else if (fl->type == '%')
		ft_putchar_count(fl->type, 1, size);
	else
		ft_putstr_count(" Error: unvalid argument ", 1, size);
}

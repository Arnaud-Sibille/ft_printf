/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:11:15 by asibille          #+#    #+#             */
/*   Updated: 2022/01/13 07:17:49 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t			i;
	int				size;
	va_list			ptr_arg;
	t_conv_flags	fl;

	i = 0;
	size = 0;
	va_start(ptr_arg, format);
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar_count(format[i++], 1, &size);
		else
		{
			++i;
			ft_init_conv_flags(&fl);
			ft_fill_conv_flags(&fl, format, &i);
			ft_print_conv(ptr_arg, &fl, &size);
		}
	}
	va_end(ptr_arg);
	return (size);
}

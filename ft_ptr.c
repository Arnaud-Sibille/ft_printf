/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:04:12 by asibille          #+#    #+#             */
/*   Updated: 2022/01/18 10:04:18 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_find_div(size_t ptr)
{
	size_t	div;

	div = 1152921504606846976;
	while (!(ptr / div))
		div /= 16;
	return (div);
}

static void	ft_fill_hexaset(char *hexaset)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		hexaset[i] = '0' + i;
		++i;
	}
	while (i < 16)
	{
		hexaset[i] = 'a' + i - 10;
		++i;
	}
}

static void	ft_putptr_count(size_t ptr, int fd, int *size)
{
	char	hexaset[16];
	size_t	div;

	ft_fill_hexaset(hexaset);
	if (!ptr)
		div = 1;
	else
		div = ft_find_div(ptr);
	ft_putstr_count("0x", 1, size);
	while (div > 1)
	{
		ft_putchar_count(hexaset[ptr / div], fd, size);
		ptr %= div;
		div /= 16;
	}
	ft_putchar_count(hexaset[ptr], fd, size);
}

void	ft_ptr(void *ptr, t_conv_flags *fl, int *size)
{
	fl->hashtag = 1;
	if (!(fl->minus))
		ft_flag_width_x((size_t) ptr, fl, size);
	if ((fl->point) || ptr || !(fl->ispoint))
		ft_putptr_count((size_t) ptr, 1, size);
	if (fl->minus)
		ft_flag_width_x((size_t) ptr, fl, size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns_hexa_maj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 10:09:24 by asibille          #+#    #+#             */
/*   Updated: 2022/01/18 10:09:27 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_find_div(size_t u)
{
	size_t	div;

	div = 16;
	while (u / div)
	{
		div *= 16;
	}
	return (div / 16);
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
		hexaset[i] = 'A' + i - 10;
		++i;
	}
}

static void	ft_putuns_he_ma_count(size_t u, int fd, int *size, t_conv_flags *fl)
{
	char	hexaset[16];
	size_t	div;

	ft_fill_hexaset(hexaset);
	div = ft_find_div((size_t) u);
	if (fl->hashtag && u)
		ft_putstr_count("0X", 1, size);
	while (div > 1)
	{
		ft_putchar_count(hexaset[u / div], fd, size);
		u %= div;
		div /= 16;
	}
	ft_putchar_count(hexaset[u], fd, size);
}

void	ft_uns_hexa_maj(unsigned int u, t_conv_flags *fl, int *size)
{
	if (!fl->minus)
		ft_flag_width_x((size_t) u, fl, size);
	ft_flag_point_x((size_t) u, fl, size);
	if ((fl->point) || u || !(fl->ispoint))
		ft_putuns_he_ma_count((size_t) u, 1, size, fl);
	if (fl->minus)
		ft_flag_width_x((size_t) u, fl, size);
}

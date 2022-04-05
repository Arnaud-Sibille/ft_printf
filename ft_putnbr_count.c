/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:05:14 by asibille          #+#    #+#             */
/*   Updated: 2022/01/19 13:05:16 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_find_div_bis(size_t u)
{
	size_t	div;

	div = 10;
	while (u / div)
		div *= 10;
	return (div / 10);
}

void	ft_putnbr_count(size_t u, int fd, int *size)
{
	size_t	div;

	div = ft_find_div_bis(u);
	while (div > 1)
	{
		ft_putchar_count((u / div) + '0', fd, size);
		u = u % div;
		div = div / 10;
	}
	ft_putchar_count(u + '0', fd, size);
}

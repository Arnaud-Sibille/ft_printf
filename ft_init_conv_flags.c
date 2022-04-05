/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_conv_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:58:50 by asibille          #+#    #+#             */
/*   Updated: 2022/01/18 09:58:52 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_conv_flags(t_conv_flags *fl)
{
	fl->minus = 0;
	fl->zero = 0;
	fl->ispoint = 0;
	fl->point = 0;
	fl->width = 0;
	fl->hashtag = 0;
	fl->space = 0;
	fl->plus = 0;
	fl->type = 0;
}

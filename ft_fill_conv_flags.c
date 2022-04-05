/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_conv_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:55:27 by asibille          #+#    #+#             */
/*   Updated: 2022/01/18 09:55:32 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_conv_flags(t_conv_flags *fl, const char *s, size_t *i)
{
	while (s[*i] == '-' || s[*i] == '0'
		|| s[*i] == '#' || s[*i] == '+' || s[*i] == ' ')
	{
		if (s[*i] == '-')
			fl->minus = 1;
		else if (s[*i] == '0')
			fl->zero = 1;
		else if (s[*i] == '#')
			fl->hashtag = 1;
		else if (s[*i] == '+')
			fl->plus = 1;
		else if (s[*i] == ' ')
			fl->space = 1;
		++(*i);
	}
	fl->width = ft_atoi(&s[*i]);
	while (ft_isdigit(s[*i]))
		++(*i);
	if (s[*i] == '.' && ++(*i))
		fl->ispoint = 1;
	fl->point = ft_atoi(&s[*i]);
	while (ft_isdigit(s[*i]))
		++(*i);
	fl->type = s[*i];
	++(*i);
}

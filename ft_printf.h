/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:10:41 by asibille          #+#    #+#             */
/*   Updated: 2022/01/12 19:14:40 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct flags
{
	int		minus;
	int		zero;
	int		point;
	int		width;
	int		hashtag;
	int		space;
	int		plus;
	char	type;
	int		ispoint;
}			t_conv_flags;

int		ft_printf(const char *format, ...);
void	ft_init_conv_flags(t_conv_flags *fl);
void	ft_fill_conv_flags(t_conv_flags *fl, const char *s, size_t *i);
void	ft_print_conv(va_list ptr_arg, t_conv_flags *fl, int *size);
void	ft_char(char c, t_conv_flags *fl, int *size);
void	ft_str(char *s, t_conv_flags *fl, int *size);
void	ft_ptr(void *ptr, t_conv_flags *fl, int *size);
void	ft_int_dec(int n, t_conv_flags *fl, int *size);
void	ft_uns_dec(unsigned int u, t_conv_flags *fl, int *size);
void	ft_uns_hexa(unsigned int u, t_conv_flags *fl, int *size);
void	ft_uns_hexa_maj(unsigned int u, t_conv_flags *fl, int *size);
void	ft_putchar_count(char c, int fd, int *count);
void	ft_putnbr_count(size_t n, int fd, int *size);
void	ft_putstr_count(char *s, int fd, int *count);
void	ft_flag_point_d(size_t u, t_conv_flags *fl, int *size);
void	ft_flag_width_d(size_t u, t_conv_flags *fl, int *size, int isneg);
void	ft_flag_plus_space_d(t_conv_flags *fl, int *size, int isneg);
void	ft_flag_width_x(size_t u, t_conv_flags *fl, int *size);
void	ft_flag_width_s(char *s, t_conv_flags *fl, int *size);
void	ft_flag_point_x(size_t u, t_conv_flags *fl, int *size);

#endif

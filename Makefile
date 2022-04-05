# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asibille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/05 11:53:37 by asibille          #+#    #+#              #
#    Updated: 2022/01/11 13:34:32 by asibille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_char.c ft_fill_conv_flags.c ft_flag_plus_space_d.c ft_flag_point_d.c ft_flag_point_x.c ft_flag_width_d.c ft_flag_width_s.c ft_flag_width_x.c ft_init_conv_flags.c ft_int_dec.c ft_print_conv.c ft_printf.c ft_ptr.c ft_putchar_count.c ft_putnbr_count.c ft_putstr_count.c ft_str.c ft_uns_dec.c ft_uns_hexa_maj.c ft_uns_hexa.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	make -C libft all
	cp libft/libft.a .
	mv libft.a libftprintf.a
	ar r ${NAME} ${OBJS}

all : ${NAME}

bonus : all

clean: 
	make fclean -C libft
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:00:44 by ogorfti           #+#    #+#              #
#    Updated: 2023/01/29 22:40:59 by ogorfti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c\
		ft_count_dec.c\
		ft_formats.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_putchar.c\
		ft_unsigned.c\
		ft_hex2big.c\
		ft_hex2smallx.c\
		ft_void.c\
		ft_count_hex.c\

NAME = libftprintf.a

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

OBJS = ${SRCS:.c=.o}

%.o : %.c
			@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS}
			@ar rcs ${NAME} ${OBJS}
			
all : ${NAME}

clean :
		@${RM} ${OBJS}

fclean : clean
		@${RM} ${NAME}

re : fclean all


		
		
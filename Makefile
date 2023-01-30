# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 12:08:04 by ogorfti           #+#    #+#              #
#    Updated: 2023/01/30 11:31:55 by ogorfti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBP = ft_printf/libftprintf.a

LIBT = libft/libft.a

SRCS_M = main.c get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\

OBJS_M = $(SRCS_M:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

GREEN = \033[1;32m

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_M)
		@make -C ft_printf
		@make -C libft
		@$(CC) $(CFLAGS) $(OBJS_M) $(LIBP) $(LIBT) -o $(NAME)

all : $(NAME)

clean :
		@make clean -C ft_printf
		@make clean -C libft
		@$(RM) $(OBJS_M)

fclean : clean
		@make fclean -C ft_printf
		@make fclean -C libft
		@$(RM) $(NAME)
		@echo "$(GREEN)DONE!"

re : fclean all

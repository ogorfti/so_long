# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 12:08:04 by ogorfti           #+#    #+#              #
#    Updated: 2023/02/09 22:09:28 by ogorfti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

LIBP = ft_printf/libftprintf.a

LIBT = libft/libft.a

LMLX = -lmlx -framework OpenGL -framework AppKit

SRCS_M = main.c get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c check_map.c check_path.c\
		allocate_map.c init_assests.c handle_keys.c handle_keys_utils.c\
		check_map_utils.c\

OBJS_M = $(SRCS_M:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

GREEN = \033[1;32m

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS_M)
		@echo "\033[36mMaking So Long...\033[0m"
		@make -C ft_printf
		@make -C libft
		@$(CC) $(CFLAGS) $(OBJS_M) $(LIBP) $(LIBT) $(LMLX) -o $(NAME)
		@echo "\033[1;32mDONE!\033[0m"

all : $(NAME)
		@echo "$(GREEN)DONE!"

clean :
		@make clean -C ft_printf
		@make clean -C libft
		@$(RM) $(OBJS_M)

fclean : clean
		@make fclean -C ft_printf
		@make fclean -C libft
		@echo "\033[36mCleaning So_Long....\033[0m"
		@$(RM) $(NAME)
		@echo "\033[1;32mDONE!\033[0m"

re : fclean all

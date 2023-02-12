# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ogorfti <ogorfti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 12:08:04 by ogorfti           #+#    #+#              #
#    Updated: 2023/02/12 12:14:32 by ogorfti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

LIBP = ft_printf/libftprintf.a

LIBFT = libft/libft.a

LMLX = -lmlx -framework OpenGL -framework AppKit

SRCS_M = mandatory/main.c get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c mandatory/check_map.c mandatory/check_path.c\
		mandatory/allocate_map.c mandatory/init_assests.c mandatory/handle_keys.c\
		mandatory/handle_keys_utils.c mandatory/check_map_utils.c mandatory/free.c\

SRCS_B = bonus/main_bonus.c bonus/allocate_map_bonus.c get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c bonus/check_map_bonus.c\
		bonus/check_map_bonus_utils.c bonus/free_bonus.c bonus/check_path_bonus.c\
		bonus/init_assests_bonus.c bonus/handle_keys_bonus.c\

OBJS_M = $(SRCS_M:.c=.o)

OBJS_B = $(SRCS_B:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

GREEN = \033[1;32m

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS_M)
		@echo "\033[36mMaking So Long...\033[0m"
		@make -C ft_printf
		@make -C libft
		@$(CC) $(CFLAGS) $(OBJS_M) $(LIBP) $(LIBFT) $(LMLX) -o $(NAME)
		@echo "\033[1;32mDONE!\033[0m"

$(NAME_BONUS) : $(OBJS_B)
		@echo "\033[36mMaking So Long Bonus...\033[0m"
		@make -C ft_printf
		@make -C libft
		@$(CC) $(CFLAGS) $(OBJS_B) $(LIBP) $(LIBFT) $(LMLX) -o $(NAME_BONUS)	
		@echo "\033[1;32mDONE BONUS!\033[0m"

clean :
		@make clean -C ft_printf
		@make clean -C libft
		@$(RM) $(OBJS_M)
		@$(RM) $(OBJS_B)

fclean : clean
		@make fclean -C ft_printf
		@make fclean -C libft
		@echo "\033[36mCleaning So_Long....\033[0m"
		@$(RM) $(NAME)
		@$(RM) $(NAME_BONUS)
		@echo "\033[1;32mDONE!\033[0m"

re : fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:21:36 by mliew             #+#    #+#              #
#    Updated: 2022/08/19 19:32:00 by mliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
RM		=	rm -rf
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	main.c img.c vars.c
OBJS	=	$(SRCS:.c=.o)
MLX		=	-lmlx -framework OpenGL -framework AppKit
LIBFT	=	-Llibft -lft
PRINTF	=	-Lft_printf -lftprintf
SANITIZE=	-fsanitize=address -g3

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) -o $(NAME) #$(SANITIZE)

clean:
	$(RM) $(OBJS)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	$(RM) $(NAME) $(ARCLIB)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all
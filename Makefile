# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliew <mliew@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:21:36 by mliew             #+#    #+#              #
#    Updated: 2023/09/16 15:57:09 by mliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
RM		=	rm -rf
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
SRCS	=	main.c utils.c vars.c check.c print.c animation.c
OBJS	=	$(SRCS:.c=.o)
MLXFLAG	=	-I/usr/include -Imlx_linux -O3
LIBFT	=	-Llibft -lft
PRINTF	=	-Lft_printf -lftprintf
SANITIZE=	-fsanitize=address -g3

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
	MLXFLAGS2	= -Lmlx_linux -lmlx_Linux -L/usr/lib -I/usr/include -Imlx_linux -lXext -lX11 -lm -lz
endif
ifeq ($(UNAME), Darwin)
	MLXFLAGS2	= -lmlx -framework OpenGL -framework AppKit -Imlx
endif

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) $(MLXFLAGS2) -o $(NAME) #$(SANITIZE)

clean:
	$(RM) $(OBJS)
	make clean -C libft
	make clean -C ft_printf

fclean: clean
	$(RM) $(NAME) $(ARCLIB)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all
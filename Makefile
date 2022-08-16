# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:21:36 by mliew             #+#    #+#              #
#    Updated: 2022/08/16 16:52:13 by mliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
OBJ		=	main.c
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all: libft $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) so_long.a -lmlx -framework OpenGL -framework AppKit -o $(NAME) #-fsanitize=address -g3

libft:
	make -C libft
	cp libft/libft.a .
	mv libft.a so_long.a

fclean:
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mliew < mliew@student.42kl.edu.my>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 17:58:41 by mliew             #+#    #+#              #
#    Updated: 2022/08/15 18:36:04 by mliew            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY	=	isalpha isalnum isprint isascii isdigit \
				tolower toupper strlen bzero atoi		\
				memcpy memmove memset memcmp memchr		\
				strlcpy strlcat strchr strrchr strncmp	\
				strnstr calloc strdup strjoin substr	\
				strtrim	itoa strmapi striteri split		\
				putchar_fd putstr_fd putendl_fd putnbr_fd

SRCS		=	$(addprefix ft_, $(addsuffix .c, $(MANDATORY)))

BONUS		=	lstnew lstadd_front lstsize lstlast lstadd_back	\
				lstdelone lstclear lstiter lstmap 

SRCSB		=	$(addprefix ft_, $(addsuffix .c, $(BONUS)))

NAME		=	libft.a
OBJS		=	$(SRCS:.c=.o)
OBJSB		=	$(SRCSB:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror -I ./
CC			=	gcc
RM			=	rm -f
AR			=	ar rcs

all: printf $(NAME) bonus

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

printf:
	make -C ft_printf
	cp ft_printf/libftprintf.a .
	mv libftprintf.a $(NAME)

bonus: $(OBJSB)
	$(AR) $(NAME) $(OBJSB)

clean:
	$(RM) $(OBJS) $(OBJSB)
	make clean -C ft_printf

fclean: clean
	$(RM) $(NAME)
	make fclean -C ft_printf
		
re: fclean all

.PHONY: $(NAME) all clean fclean re bonus printf
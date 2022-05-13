# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 16:54:06 by tbeaudoi          #+#    #+#              #
#    Updated: 2022/05/12 17:03:40 by tbeaudoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = gcc

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
		ar -rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
		
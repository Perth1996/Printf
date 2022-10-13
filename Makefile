# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plawkiat <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/06 13:12:08 by plawkiat          #+#    #+#              #
#    Updated: 2022/10/12 07:10:28 by plawkiat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

SRCS =	ft_printf.c \
	ft_cspx.c \
	ft_diu.c \

OBJS = $(SRCS:.c=.o)

all:	$(NAME)

%o:%c
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) 

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean all re

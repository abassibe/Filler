# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abassibe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/01 12:45:46 by abassibe          #+#    #+#              #
#    Updated: 2017/09/28 03:34:59 by abassibe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = abassibe.filler

SRCS =	filler.c \
		algo.c \
		range.c \
		parcing.c \
		parcing_2.c \
		mlx.c \
		display_infos.c \
		display_infos_next.c

OBJS = $(SRCS:.c=.o)

SRCPATH = ./srcs/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@gcc $(FLAGS) $(OBJS) libft/libft.a ressources/libmlx.a -o $(NAME) \
		-L. -framework OpenGL -framework AppKit

%.o: $(SRCPATH)%.c
	@gcc $(FLAGS) -c $< -I includes/filler.h

.PHONY: all clean fclean re

clean:
	@make -C libft clean
	@rm -rf $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -rf libft/libft.a $(NAME)

re: fclean all

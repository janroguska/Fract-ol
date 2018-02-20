# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroguszk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/01 10:39:30 by jroguszk          #+#    #+#              #
#    Updated: 2018/02/01 10:47:17 by jroguszk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = fractol.c draw.c fractals.c input.c

OBJ = $(SRC:.c=.o)

LIBFT = includes/libft/libft.a

MINILIBX = minilibx/libmlx.a

HEADER = -c -I fractol.h

all: $(NAME)

$(OBJ): %.o: %.c
		@gcc -c -Wall -Werror -Wextra -I includes/libft/ $< -o $@

$(LIBFT):
	@make -C includes/libft

$(MINILIBX):
	@make -C minilibx

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) $(MINILIBX) -o $(NAME) -framework OpenGL -framework AppKit

clean:
	/bin/rm -f $(OBJ)
	@make -C includes/libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C includes/libft fclean

re: fclean all

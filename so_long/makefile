# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mehmyild <mehmyild@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/08 00:09:27 by mehmyild          #+#    #+#              #
#    Updated: 2023/09/14 11:47:23 by mehmyild         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := main.c map_control.c press_image.c movement_control.c input.c utils.c start_game.c map_validation.c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit

MINILIBX	=	minilibx

all:				$(NAME)

$(NAME): mlx
					$(CC) $(CFLAGS) -o $(NAME) $(SOURCE) -framework OpenGL -framework AppKit -L$(MINILIBX) -lmlx


mlx:
					make -C $(MINILIBX) all

clean:
					$(RM) $(NAME)

fclean: clean
					make clean -C $(MINILIBX)
					
re:					fclean mlx all

.PHONY:				all clean fclean re 

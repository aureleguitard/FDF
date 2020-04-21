# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: auguitar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 22:21:46 by auguitar          #+#    #+#              #
#    Updated: 2019/10/11 02:48:50 by auguitar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = read_file.c lists.c \
	  transform_lists.c \
	  draw.c main.c fdf.c

OBJ = read_file.o lists.o \
	  transform_lists.o \
	  draw.o main.o fdf.o

HEADERS = fdf.h minilibx_macos/mlx.h

LIBRARIES = -L minilibx_macos -lmlx -L libft -lft

FRAMEWORKS = -framework OpenGl -framework Appkit

CFLAGS = -Wall -Wextra -Werror

CC = gcc

all: $(NAME)

$(NAME):$(OBJ)
	@make -C libft/
	@make -C minilibx_macos/
	@gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(LIBRARIES) $(FRAMEWORKS)

clean:
	#Cleaning
	@make clean -C libft/
	@make clean -C minilibx_macos/
	@/bin/rm -f $(OBJ)

fclean: clean
	#Fcleaning
	make fclean -C libft/
	@/bin/rm -f $(NAME)

re: fclean all

PHONY : fclean clean all re

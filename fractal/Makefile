# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdoumane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 13:55:09 by mdoumane          #+#    #+#              #
#    Updated: 2025/01/08 13:57:23 by mdoumane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ftcl

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoire de la bibliothèque MiniLibX
MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

SRC = $(shell find ./src -name "*.c")
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR) # Compile la minilibx-linux si nécessaire
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_LIB) $(MLX_FLAGS)

bonus: $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(OBJ) $(MLX_LIB) $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(MLX_DIR) clean

re: fclean all


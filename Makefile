# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 18:34:14 by asoria            #+#    #+#              #
#    Updated: 2025/11/07 02:38:17 by asoria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fract-ol
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iincludes -Ilibft -g3 -O3 -march=native -flto -pipe

SRC_DIR		:= src
SRC_FILES	:= $(wildcard $(SRC_DIR)/*.c)

OBJ_DIR		:= obj
OBJ_FILES	:=$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Libraries
LIBFT_DIR	:= includes/libft
LIBFT		:= $(LIBFT_DIR)/libft.a

MINILIBX_DIR	:= includes/minilibx-linux
MINILIBX	:= $(MINILIBX_DIR)/libmlx_Linux.a

all: $(NAME)
# Compiles source into obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensures obj/ exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(MINILIBX) -lX11 -lXext -o $(NAME)
	@echo -e "\033[32m[✔] Built $(NAME)\033[0m"
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MINILIBX_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: clean all

.PHONY: all clean fclean re

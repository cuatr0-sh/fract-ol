# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoria <asoria@student.42madrid.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24 18:34:14 by asoria            #+#    #+#              #
#    Updated: 2025/10/24 19:06:40 by asoria           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fract-ol
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror -Iincludes -Ilibft -g3 -O3 -march=native -flto -pipe

SRC_DIR		:= src/
SRC_FILES	:= $(wildcard $(SRC_DIR)/*.c)
OBJ_DIR		:= obj/
OBJ_FILES	:=$(SRC_FILES:.c=.o)

#Libraries
LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a

MINILIBX_DIR	:= minilibx-linux
MINILIBX	:= $(MINILIBX_DIR)/libmlx_Linux.a

#Targets
all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) $(MINILIBX) -lX11 -lXext -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBX_DIR)


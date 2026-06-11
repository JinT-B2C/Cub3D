# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: torasolo <torasolo@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 17:57:25 by torasolo          #+#    #+#              #
#    Updated: 2026/06/11 03:52:41 by torasolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux

GNL = gnl
LIB = lib
MLX = minilibx-linux

GNL_L = $(GNL)/get_next_line.c $(GNL)/get_next_line_utils.c
LIB_L = $(LIB)/libft.a
MLX_L = -L$(MLX) -lmlx -lX11 -lXext -lm

SRC = main.c \
		path.c \
		readfl.c \
		parse.c \
		init_conf.c \
		free.c \
		map_utils.c \
    	game_init.c \
		render.c \
		events.c \
		raycasting.c \
		raycasting_utils.c \
		movement.c \
		mov_utils.c \
		textures.c \
		error.c \
		draw_utils.c \
		ray_data_utils.c \
		Flood_fill.c \
		get_map.c \
		validate_map.c \
		parse2.c \
		line_proc.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(MLX)/libmlx.a:
	@make -C $(MLX)

$(LIB)/libft.a:
	@make -C $(LIB)

$(NAME): $(LIB)/libft.a $(MLX)/libmlx.a $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(GNL_L) $(LIB_L) $(MLX_L)
	@echo "✅ cub3D compiled!"

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIB)
	@make clean -C $(MLX)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB)

bonus: all

re: fclean all

.PHONY: all clean fclean re bonus

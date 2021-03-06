# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlucille <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 11:41:17 by tlucille          #+#    #+#              #
#    Updated: 2020/06/09 12:34:58 by tlucille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIB_DIR = libft/

LIBFT_A = libft.a

FILE_DIR = srcs

INC_DIR = srcs

INCLUDES = $(FILE_DIR)/cub3d.h		\

SRC = $(FILE_DIR)/bmp_maker.c	\
	$(FILE_DIR)/bmp_master.c		\
	$(FILE_DIR)/check_map.c 	\
	$(FILE_DIR)/check_map_char.c 	\
	$(FILE_DIR)/fill_int_map.c		\
	$(FILE_DIR)/free_int_tab.c		\
	$(FILE_DIR)/free_parse.c		\
	$(FILE_DIR)/free_stuff.c		\
	$(FILE_DIR)/free_stuff_2.c		\
	$(FILE_DIR)/free_tex.c		\
	$(FILE_DIR)/ft_cub_split.c		\
	$(FILE_DIR)/get_cub_tab.c		\
	$(FILE_DIR)/get_floor_ceiling.c		\
	$(FILE_DIR)/get_sprite_distance.c		\
	$(FILE_DIR)/get_sprites.c		\
	$(FILE_DIR)/init_tex.c		\
	$(FILE_DIR)/tex_utils.c		\
	$(FILE_DIR)/mlx_start.c		\
	$(FILE_DIR)/start_utils.c		\
	$(FILE_DIR)/move_rotate.c		\
	$(FILE_DIR)/move.c		\
	$(FILE_DIR)/parse_master.c		\
	$(FILE_DIR)/error_get_res.c		\
	$(FILE_DIR)/parse_tex.c		\
	$(FILE_DIR)/put_sprites.c		\
	$(FILE_DIR)/put_tex.c		\
	$(FILE_DIR)/ray_casting.c		\
	$(FILE_DIR)/initialize_fov.c		\
	$(FILE_DIR)/rotate.c		\
	$(FILE_DIR)/set_fov.c		\
	$(FILE_DIR)/sort_sprites.c		\
	$(FILE_DIR)/verify_int_map.c		\

CC = clang

LIB_MAKER = make -C

OBJS = $(patsubst %.c, %.o,$(SRC))

%.o: %.c
	$(CC) -c $< -o $@ $(FLAGS)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB_MAKER) $(LIB_DIR)
	$(LIB_MAKER) mlx
	clang -o $(NAME) -I srcs  $(OBJS) -Lmlx -lmlx -Llibft -lft -lm -lbsd -lX11 -lXext

clean: 
	$(LIB_MAKER) $(LIB_DIR) clean
	/bin/rm -f $(OBJS)

fclean: clean
	$(LIB_MAKER) $(LIB_DIR) fclean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all

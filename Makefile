# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcredibl <gcredibl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/15 15:01:11 by gcredibl          #+#    #+#              #
#    Updated: 2021/04/27 22:53:32 by gcredibl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	srcs/main.c srcs/exit.c srcs/save.c \
					parser/map_parser.c parser/config_parser.c \
					init/init_mem.c init/init_config.c init/init_player.c \
					init/world_side.c init/check_config.c \
					moves/move.c moves/update.c moves/rotation.c \
					gnl/get_next_line.c gnl/get_next_line_utils.c \
					draw/draw_utils.c draw/draw_walls.c \
					draw/draw_sprites.c draw/ray_cast_walls.c \
					draw/draw.c \

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror
MLX				= libmlx.dylib
LIBFT			= libft.a

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(LIBFT) $(MLX) $(OBJS) cub3d.h
				gcc ${CFLAGS} -o ${NAME} $(OBJS) ${LIBFT} ${MLX} -fsanitize=address

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

$(LIBFT):
				@$(MAKE) -C libft
				@mv libft/$(LIBFT) .

clean:
				@$(MAKE) -C mlx clean
				@$(MAKE) -C libft clean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX) $(LIBFT)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 14:16:38 by mpedraza          #+#    #+#              #
#    Updated: 2026/01/24 16:44:07 by mpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CFLAGS		= 	-Wall -Wextra -Werror

HEADER		=	so_long.h
FILES		=	so_long init parse validate load render input print exit \
				helper_gnl \
				utils_flood utils_string
SRCS		=	${FILES:%=%.c}
OBJS		=	${SRCS:%.c=%.o}

IMAGES		=	a c e f p pa pc pca pcab w
ASSETS		= 	${IMAGES:%=img/%.xpm}

MLX_DIR		=	mlx
MLX_REPO	=	https://github.com/42Paris/minilibx-linux.git
MLX_LIB     = 	${MLX_DIR}/libmlx.a


# FOR AGRESSIVE OPTIMIZATION
%.o: %.c ${HEADER} | $(MLX_LIB)
	$(CC) ${CFLAGS} -I${MLX_DIR} -O3 -c $< -o $@

# FOR DEBUGGING
#%.o: %.c ${HEADER} | $(MLX_LIB)
#	${CC} ${CFLAGS} -I${MLX_DIR} -O0 -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} $(MLX_LIB) ${ASSETS}
	${CC} ${OBJS} -L${MLX_DIR} -lmlx -Imlx -lXext -lX11 -lm -lz -o ${NAME}

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning MiniLibX..."; \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@echo "Building MiniLibX..."
	@cd $(MLX_DIR) && ./configure

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	${RM} -rf ${MLX_DIR}

re: fclean all

.PHONY: all clean fclean re
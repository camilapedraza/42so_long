# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 14:16:38 by mpedraza          #+#    #+#              #
#    Updated: 2026/01/25 16:54:14 by mpedraza         ###   ########.fr        #
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

UNAME		:=	$(shell uname)

MLX_DIR		=	mlx

ifeq ($(UNAME), Linux)
	MLX_REPO = https://github.com/42Paris/minilibx-linux.git
	MLX_LIB  = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -lmlx -Imlx -lXext -lX11 -lm -lz
endif

ifeq ($(UNAME), Darwin)
	MLX_REPO = https://github.com/camilapedraza/42minilibx-macos.git
	MLX_LIB  = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -lmlx -Imlx -framework OpenGL -framework AppKit
endif

ifeq ($(UNAME), Linux)
    CFLAGS += -DLINUX
endif

ifeq ($(UNAME), Darwin)
    CFLAGS += -DMACOS
endif

# FOR AGRESSIVE OPTIMIZATION
%.o: %.c ${HEADER} | $(MLX_LIB)
	$(CC) ${CFLAGS} -I${MLX_DIR} -O3 -c $< -o $@

# FOR DEBUGGING
#%.o: %.c ${HEADER} | $(MLX_LIB)
#	${CC} ${CFLAGS} -I${MLX_DIR} -O0 -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} $(MLX_LIB) ${ASSETS}
	${CC} ${OBJS} -L${MLX_DIR} ${MLX_FLAGS} -o ${NAME}

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Cloning MiniLibX..."; \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@echo "Building MiniLibX..."
ifeq ($(UNAME), Linux)
	@cd $(MLX_DIR) && ./configure
endif
ifeq ($(UNAME), Darwin)
	@cd $(MLX_DIR) && make
endif

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}
	${RM} -rf ${MLX_DIR}

re: fclean all

.PHONY: all clean fclean re
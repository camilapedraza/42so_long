# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 14:16:38 by mpedraza          #+#    #+#              #
#    Updated: 2026/01/21 18:56:34 by mpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CFLAGS		= 	-Wall -Wextra -Werror

FILES		=	so_long parse validate load init render input helpers_gnl \
				utils_flood utils_string
SRCS		=	${FILES:%=%.c}
OBJS		=	${SRCS:%.c=%.o}

IMAGES		=	a c f p pa pc pca w
ASSETS		= 	${IMAGES:%=img/%.xpm}

# TODO NEED TO INCLUDE RULE TO CLONE MLX PROJECT, CONFIGURE BEFORE ANYTHING ELSE!

# FOR AGRESSIVE OPTIMIZATION WHEN DONE DEBUGGING
#%.o: %.c
#	$(CC) ${CFLAGS} -Imlx -O3 -c $< -o $@

# FOR DEBUGGING
%.o: %.c
	${CC} ${CFLAGS} -Imlx -g -O0 -c $< -o $@

all: ${NAME}

# TODO make sure name re-runs if header file changes
${NAME}: ${OBJS} ${ASSETS} 
	${CC} ${OBJS} -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
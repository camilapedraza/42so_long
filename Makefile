# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 14:16:38 by mpedraza          #+#    #+#              #
#    Updated: 2026/01/23 16:41:32 by mpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CFLAGS		= 	-Wall -Wextra -Werror

HEADER		=	so_long.h
FILES		=	so_long init parse validate load render input print \
				helper_gnl \
				utils_flood utils_string
SRCS		=	${FILES:%=%.c}
OBJS		=	${SRCS:%.c=%.o}

IMAGES		=	a c e f p pa pc pca pcab w
ASSETS		= 	${IMAGES:%=img/%.xpm}

# TODO NEED TO INCLUDE RULE TO CLONE MLX PROJECT, CONFIGURE BEFORE ANYTHING ELSE!

# FOR AGRESSIVE OPTIMIZATION WHEN DONE DEBUGGING
#%.o: %.c
#	$(CC) ${CFLAGS} -Imlx -O3 -c $< -o $@

# FOR DEBUGGING
%.o: %.c ${HEADER}
	${CC} ${CFLAGS} -Imlx -g -O0 -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} ${ASSETS} 
	${CC} ${OBJS} -g -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
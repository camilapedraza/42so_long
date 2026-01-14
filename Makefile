# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 14:16:38 by mpedraza          #+#    #+#              #
#    Updated: 2026/01/14 20:03:56 by mpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CFLAGS		= 	-Wall -Wextra -Werror

SRCS		=	so_long.c
OBJS		=	${SRCS:%.c=%.o}

ASSETS		=	asset_floor asset_onigiri asset_onigiri_salmon asset_salmon \
				asset_wall
XPMS		= 	${ASSETS:%=%.xpm}


# FOR AGRESSIVE OPTIMIZATION WHEN DONE DEBUGGING
#%.o: %.c
#	$(CC) ${CFLAGS} -Imlx -O3 -c $< -o $@

# FOR DEBUGGING
%.o: %.c
	${CC} ${CFLAGS} -Imlx -g -O0 -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} ${XPMS}
	${CC} ${OBJS} -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpedraza <mpedraza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 14:16:38 by mpedraza          #+#    #+#              #
#    Updated: 2026/01/15 16:15:01 by mpedraza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	cc
CFLAGS		= 	-Wall -Wextra -Werror

SRCS		=	so_long.c
OBJS		=	${SRCS:%.c=%.o}

FILES		=	c1 f p0 p1 w
ASSETS		= 	${FILES:%=img/%.xpm}


# FOR AGRESSIVE OPTIMIZATION WHEN DONE DEBUGGING
#%.o: %.c
#	$(CC) ${CFLAGS} -Imlx -O3 -c $< -o $@

# FOR DEBUGGING
%.o: %.c
	${CC} ${CFLAGS} -Imlx -g -O0 -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} ${ASSETS} 
	${CC} ${OBJS} -Lmlx -lmlx -Imlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
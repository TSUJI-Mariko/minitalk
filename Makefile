# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/27 16:20:23 by mtsuji            #+#    #+#              #
#    Updated: 2021/12/27 16:20:27 by mtsuji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT	=	client

NAME_SERVER	=	server

SRCS_CLIENT	=	./srcs/client.c	\
				./srcs/outil.c	\

SRCS_SERVER	=	./srcs/server.c	\
				./srcs/outil.c	\

OBJS_CLIENT	=	${SRCS_CLIENT:.c=.o}

OBJS_SERVER	=	${SRCS_SERVER:.c=.o}

HEADER	=	./includes/minitalk.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

.c.o:
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

all:	${NAME_CLIENT} ${NAME_SERVER}
$(NAME_CLIENT):	${OBJS_CLIENT}
$(NAME_SERVER):	${OBJS_SERVER}
			${CC} ${CFLAGS} ${SRCS_CLIENT} -o ${NAME_CLIENT}
			${CC} ${CFLAGS} ${SRCS_SERVER} -o ${NAME_SERVER}

clean:
		${RM} ${OBJS_CLIENT} ${OBJS_SERVER}
fclean:		clean
		${RM} $(NAME_CLIENT) $(NAME_SERVER)
re:	fclean all

.PHONY:	all clean fclean re

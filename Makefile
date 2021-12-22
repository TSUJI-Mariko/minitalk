# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtsuji <mtsuji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 22:03:46 by mtsuji            #+#    #+#              #
#    Updated: 2021/12/22 18:33:47 by mtsuji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memmove.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlen.c		\
			ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strncmp.c	\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_strnstr.c	\
			ft_atoi.c		\
			ft_calloc.c		\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\

NAME_CLIENT	=	client

NAME_SERVER	=	server

SRCS_CLIENT	=	

SRCS_SERVER	=	

OBJS_CLIENT	=	${SRCS_CLIENT:.c=.o}

OBJS_SERVER	=	${SRCS_SERVER:.c=.o}

HEADER	=	./includes/minitalk.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

NAME	=	libft.a

.c.o:
	${CC} ${CFLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

all:	${NAME_CLIENT} ${NAME_SERVER}
${NAME_CLIENT}:	${OBJS_CLIENT}
${NAME_SERVER}:	${OBJS_SERVER}
			${CC} ${CFLAGS} ${SRCS_CLIENT} -o ${NAME_CLIENT}
			${CC} ${CFLAGS} ${SRCS_SERVER} -o ${NAME_SERVER}

clean:
		${RM} ${OBJS_CLIENT} ${OBJS_SERVER}
fclean:		clean
		${RM} $(NAME_CLIENT) $(NAME_SERVER)
re:	fclean all

.PHONY:	all clean fclean re server client

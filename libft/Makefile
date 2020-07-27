# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 11:40:31 by nsahloum          #+#    #+#              #
#    Updated: 2020/07/27 18:57:44 by nsahloum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_isalnum.c 	\
			ft_isascii.c 	\
			ft_isprint.c	\
			ft_strchr.c		\
			ft_strlen.c		\
			ft_strncmp.c	\
			ft_strrchr.c	\
			ft_tolower.c	\
			ft_toupper.c	\
			ft_isdigit.c	\
			ft_isalpha.c	\
			ft_memset.c		\
			ft_bzero.c		\
			ft_memmove.c	\
			ft_memcpy.c		\
			ft_memccpy.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_strnstr.c	\
			ft_atoi.c		\
			ft_calloc.c		\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_itoa.c		\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_putnbr_u_fd.c \
			ft_split.c		\
			ft_strmapi.c	\
			ft_putnbr_base_fd.c \
			ft_abs.c \
			ft_lastchar.c \
			ft_len_num.c \
			ft_len_nbr_u.c \

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc $(NAME) ${OBJS}

all:
	@make -j$(nproc) $(NAME)

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

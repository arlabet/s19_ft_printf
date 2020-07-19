# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 16:01:36 by nsahloum          #+#    #+#              #
#    Updated: 2020/07/19 15:04:32 by nsahloum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRCS		=	ft_all_prints_csp.c ft_all_prints_dux.c ft_printf.c \

OBJS		= $(SRCS:.c=.o)
LIBFT		= ./libft
HEADER		= ./
%.o: %.c
	gcc -c -I$(HEADER) -o $@ $<
all: makelib $(NAME)
$(NAME): $(OBJS)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)
makelib:
	make -C $(LIBFT)
clean:
	/bin/rm -f $(OBJS)
	make clean -C $(LIBFT)
fclean:     clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT)
re: fclean all
.PHONY: all clean fclean re

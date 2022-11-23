# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lperrin <lperrin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 15:35:14 by lperrin           #+#    #+#              #
#    Updated: 2022/11/21 14:45:20 by lperrin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g
LIBMLX	= srcs/lib/MLX42
LIBFTDIR	= srcs/lib/libft

HEADERS	= -I $(LIBMLX)/include
GLFW	= /System/Volumes/Data/sgoinfre/goinfre/Perso/lperrin/homebrew/Cellar/glfw/3.3.8/lib
LIBS	= -ldl -lglfw -L $(GLFW) -pthread -lm $(LIBMLX)/libmlx42.a
SRCS	= 	srcs/fractal/test.c \
			srcs/fractal/init.c \
			srcs/fractal/put_error.c \
			srcs/fractal/render.c \
			srcs/fractal/utils.c \
			srcs/fractal/thegroove.c

LIBFT = srcs/lib/libft/libft.a
OBJS	= ${SRCS:.c=.o}
CC		= gcc

all: libmlx libft $(NAME)

libmlx:
	@$(MAKE) -C $(LIBMLX)

libft:
	@$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LIBFT) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBMLX) clean
	@$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBMLX) fclean
	@$(MAKE) -C $(LIBFTDIR) fclean

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft

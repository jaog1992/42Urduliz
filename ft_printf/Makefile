# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 10:51:06 by jde-orma          #+#    #+#              #
#    Updated: 2023/03/17 10:51:06 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar

ARFLAGS = rc

SRC_DIR = source

INC_DIR = include

LIBFT_DIR = libft

SRCS = $(addprefix $(SRC_DIR)/, ft_printf.c ft_putptr_fd.c ft_putuint_fd.c ft_uitoa.c) \
       $(addprefix $(LIBFT_DIR)/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
        ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
        ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
        ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
        ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
        ft_substr.c ft_tolower.c ft_toupper.c)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)
	ranlib $@

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

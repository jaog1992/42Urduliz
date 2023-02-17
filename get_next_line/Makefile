# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 20:22:58 by jde-orma          #+#    #+#              #
#    Updated: 2023/02/15 20:22:58 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## The name of the variable always starts with Uppercase.

## Executable name
NAME = a.out

## gcc compilator execution flag
FLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=42

## Directory to save the executable. ./ is the default
HDR = -I ./

## Source/name of the .c files to be compiled
SRC = get_next_line.c get_next_line_utils.c

## Object files to be created
OBJ = get_next_line.c get_next_line_utils.o

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC) $(HDR)
	ar -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
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

## Executable name
NAME = get_next_line.out

## gcc compilator execution flag. Add -g3 for debugging
FLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=42
FLAG2 = -Wall -Wextra -Werror -D BUFFER_SIZE=42 -sanitize=address

## Directory to save the executable. ./ is the default
HDR = -I ./

## Source/name of the .c files to be compiled
SRC = get_next_line.c get_next_line_utils.c
## Object files to be created
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) get_next_line.h
	ar -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c get_next_line.h
	gcc $(FLAG) -c $< $(HDR) -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

create: 
	gcc $(FLAG2) $(SRC) $(HDR) -o create.out
	
.PHONY: all clean fclean re create

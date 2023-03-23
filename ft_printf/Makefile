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
# Key variable and files definitions:

NAME = libftprintf.a
LIBFT = libft/libft.a

CC = gcc
CCFLAGS = -Wall -Wextra -Werror

AR = ar rc
RM = rm -f

SRC =	source/ft_printf.c
OBJ = 	$(SRC:.c=.o)

INCLUDE = include

#Colors:

DEF_COLOR = \033[0;39m
WHITE = \033[0;97m
BLUE = \033[0;94m
GREEN = \033[0;92m

# **************************************************************************** #

all:		$(LIBFT) $(NAME)

$(NAME):	$(OBJ)
			@cp $(LIBFT) $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)✔ $(BLUE)jde-orma's printf compilation$(DEF_COLOR)"


$(LIBFT):
			@make -C ./libft

.c.o:
			@$(CC) $(CCFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ)
			@echo "$(GREEN)✔ $(BLUE)jde-orma's printf .o files removal$(WHITE)"
			@make clean -C ./libft

fclean:		clean
			@make fclean -C ./libft
			@$(RM) $(NAME)
			@echo "$(GREEN)✔ $(BLUE)jde-orma's $(NAME) removal$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re libft

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

# Coder Alias

USER_NAME	=	jde-orma

# Compiler, flags and static library ceation

CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
HDR			=	-I ./
AR			=	ar rc
RM			=	rm -f

# **************************************************************************** #

# Code implementation NAME

CODE		=	ft_printf

# Static library names:

NAME		=	libftprintf.a
LIBFT_FILE	=	libft.a

# File directories

LIBFT_DIR	=	libft/

# Source Files:

SRC	=	ft_printf.c

# Source && static library files + directories

LIBFT		=	$(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

# Object files creation

OBJ			=	$(SRC:.c=.o)

#Colors:

DEF_COLOR	=	\033[0;39m
WHITE		=	\033[0;97m
BLUE		=	\033[0;94m
GREEN		=	\033[0;92m

# **************************************************************************** #

all:		$(LIBFT) $(NAME)

# cp is a command (Unix) used to copy files/directories from loc1 to loc2
$(NAME):	$(OBJ)
			@cp $(LIBFT) $(NAME)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) compilation$(DEF_COLOR)"

# The -C flag changes the current working directory to the libft directory
$(LIBFT):
			@make -C ./libft

# Suffix/pattern rule: which tells Make to apply this rule to any target
# ending with .o and any prerequisite ending with .c.
.c.o:
			@$(CC) $(CCFLAGS) $(HDR) -c $< -o $(<:.c=.o)

# The if statement prevents the libft Makefile clean rule being called twice
# if the rule is called from the fclean
clean:
			@$(RM) $(OBJ)
			@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) .o files removal$(WHITE)"
			@if [ "$(CLEAN_CALLED_FROM_FCLEAN)" != "1" ]; then \
				make clean -C ./libft; \
			fi

fclean:
			@$(MAKE) CLEAN_CALLED_FROM_FCLEAN=1 clean
			@make fclean -C ./libft
			@$(RM) $(NAME)
			@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) removal$(DEF_COLOR)"

re:			fclean all

.PHONY:		all clean fclean re libft

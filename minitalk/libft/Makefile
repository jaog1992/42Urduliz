# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 08:02:50 by jde-orma          #+#    #+#              #
#    Updated: 2023/03/23 08:02:50 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Coder Alias

USER_NAME	=	jde-orma

# Compiler, flags and static library creation

CC			=	gcc
CCFLAGS		=	-Wall -Wextra -Werror
HDR			=	-I ./include
AR			=	ar rc
RM			=	rm -f

# **************************************************************************** #

# Code implementation NAME

CODE		=	libft

# Static library names:

NAME		=	libft.a

# Source files directory:

SRC_DIR 	=	source/

# libft functions subdirectories

FT_IS_DIR	=	ft_is/
FT_MATH_DIR	=	ft_math/
FT_MEM_DIR	=	ft_mem/
FT_PUT_DIR	=	ft_put/
FT_STR_DIR	=	ft_str/
FT_TO_DIR	=	ft_to/

# Source Files:

FT_IS		=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
FT_MATH		=	ft_pow.c
FT_MEM		=	ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_free.c
FT_PUT		=	ft_putchar_fd.c ft_puthex_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_putuint_fd.c ft_putendl_fd.c ft_printf.c ft_print_error.c
FT_STR		=	ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strtol.c\
				ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
				ft_get_next_line.c ft_gnlstrjoin.c ft_str.c ft_strncpy.c
FT_TO		=	ft_atoi.c ft_itoa.c ft_uitoa.c ft_toupper.c ft_tolower.c

# Source files

SRC	=	$(addprefix $(SRC_DIR), $(addprefix $(FT_IS_DIR), $(FT_IS))) \
		$(addprefix $(SRC_DIR), $(addprefix $(FT_MATH_DIR), $(FT_MATH))) \
		$(addprefix $(SRC_DIR), $(addprefix $(FT_MEM_DIR), $(FT_MEM))) \
		$(addprefix $(SRC_DIR), $(addprefix $(FT_PUT_DIR), $(FT_PUT))) \
		$(addprefix $(SRC_DIR), $(addprefix $(FT_STR_DIR), $(FT_STR))) \
		$(addprefix $(SRC_DIR), $(addprefix $(FT_TO_DIR), $(FT_TO))) \

# Object files creation

OBJ			=	$(SRC:.c=.o)

#Colors:

DEF_COLOR	=	\033[0;39m
WHITE		=	\033[0;97m
BLUE		=	\033[0;94m
GREEN		=	\033[0;92m

# **************************************************************************** #

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) compilation$(WHITE)"
.c.o:
			@$(CC) $(CCFLAGS) $(HDR) -c $< -o $(<:.c=.o)

clean:
			@$(RM) $(OBJ)
			@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) .o files removal$(WHITE)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(NAME) removal$(WHITE)"

re:			fclean all

.PHONY:		all clean fclean re
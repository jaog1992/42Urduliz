# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 13:51:06 by jde-orma          #+#    #+#              #
#    Updated: 2023/03/18 13:51:06 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Coder Alias

USER_NAME   =   jde-orma

# Compiler, flags and static library creation

CC          =   gcc
CCFLAGS     =   -Wall -Wextra -Werror -g
# HDR         =   -I ./
AR          =   ar rc
RM          =   rm -f

#Colors:

DEF_COLOR   =   \033[0;39m
WHITE       =   \033[0;97m
BLUE        =   \033[0;94m
GREEN       =   \033[0;92m

# **************************************************************************** #

# Code implementation NAME

CODE        =   so_long

# Static library names:

LIBFT_FILE  =   libft.a

# File directories

LIBFT_DIR   =   libft/
SRC_DIR     =   source/
OBJ_DIR     =   obj/
BIN_DIR     =   ./
INCL_DIR    =   include/

# Source files for server and client
SRC  =   $(addprefix $(SRC_DIR), *.c)

# Object files for server and client
SOURCE_OBJ  =   $(addprefix $(OBJ_DIR), *.o)

# Binary names for server and client
SOURCE_BIN  =   $(BIN_DIR)so_long

# Source and static library files + directories
LIBFT       =   $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

# **************************************************************************** #

# If the obj/ directory does not exit it creates it. If exist the Makefile continues
$(shell mkdir -p $(OBJ_DIR))

# Variable to control if the library has been built
LIBFT_BUILT = no

all: $(LIBFT) $(SOURCE_BIN) $(CLIENT_BIN)

# Build the server executable
$(SOURCE_BIN): $(SOURCE_OBJ) $(LIBFT)
	$(CC) $(CCFLAGS) $(SOURCE_OBJ) -L$(LIBFT_DIR) -lft -o $@
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) server compilation$(DEF_COLOR)"


# Build the static library libft.a only if it's not built yet
$(LIBFT):
	@if [ "$(LIBFT_BUILT)" = "no" ]; then \
		make -C $(LIBFT_DIR); \
		LIBFT_BUILT=yes; \
	fi

# Suffix/pattern rule: which tells Make to apply this rule to any target
# ending with .o and any prerequisite ending with .c.
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@$(RM) $(SOURCE_OBJ)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) .o files removal$(WHITE)"
	@make -C $(LIBFT_DIR) clean

fclean:
	@$(RM) $(SOURCE_OBJ) $(SOURCE_BIN)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) executables and .o files removal$(WHITE)"
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft

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
CCFLAGS     =   -Wall -Wextra -Werror
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

CODE        =   minitalk

# Static library names:

LIBFT_FILE  =   libft.a

# File directories

LIBFT_DIR   =   libft/
SRC_DIR     =   src/
BNS_DIR		=	bonus/
OBJ_DIR     =   obj/
BIN_DIR     =   ./
INCL_DIR    =   incl/

# Source files for server and client
SERVER_SRC  =   $(SRC_DIR)server.c
CLIENT_SRC  =   $(SRC_DIR)client.c
SERVER_BONUS_SRC  =   $(BNS_DIR)server.c
CLIENT_BONUS_SRC  =   $(BNS_DIR)client.c

# Object files for server and client
SERVER_OBJ  =   $(addprefix $(OBJ_DIR), server.o)
CLIENT_OBJ  =   $(addprefix $(OBJ_DIR), client.o)
SERVER_BONUS_OBJ  =   $(addprefix $(BNS_DIR), server_bonus.o)
CLIENT_BONUS_OBJ  =   $(addprefix $(BNS_DIR), client_bonus.o)

# Binary names for server and client
SERVER_BIN  =   $(BIN_DIR)server
CLIENT_BIN  =   $(BIN_DIR)client
SERVER_BNS_BIN  =   $(BIN_DIR)server_bonus
CLIENT_BNS_BIN  =   $(BIN_DIR)client_bonus

# Source and static library files + directories
LIBFT       =   $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

# **************************************************************************** #

all: $(LIBFT) $(SERVER_BIN) $(CLIENT_BIN)

# Build the server executable
$(SERVER_BIN): $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CCFLAGS) $(SERVER_OBJ) -L$(LIBFT_DIR) -lft -o $@
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) server compilation$(DEF_COLOR)"

# Build the client executable
$(CLIENT_BIN): $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CCFLAGS) $(CLIENT_OBJ) -L$(LIBFT_DIR) -lft -o $@
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) client compilation$(DEF_COLOR)"

# The -C flag changes the current working directory to the libft directory
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Suffix/pattern rule: which tells Make to apply this rule to any target
# ending with .o and any prerequisite ending with .c.
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CCFLAGS) -c $< -o $@

bonus: $(LIBFT) $(SERVER_BNS_BIN) $(CLIENT_BNS_BIN)

# Build the server executable
$(SERVER_BNS_BIN): $(SERVER_BONUS_OBJ) $(LIBFT)
	$(CC) $(CCFLAGS) $(SERVER_BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $@
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) bonus server compilation$(DEF_COLOR)"

# Build the client executable
$(CLIENT_BNS_BIN): $(CLIENT_BONUS_OBJ) $(LIBFT)
	$(CC) $(CCFLAGS) $(CLIENT_BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $@
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) bonus client compilation$(DEF_COLOR)"

# The -C flag changes the current working directory to the libft directory
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Suffix/pattern rule: which tells Make to apply this rule to any target
# ending with .o and any prerequisite ending with .c.
$(OBJ_DIR)%.o: $(BNS_DIR)%.c
	@$(CC) $(CCFLAGS) -c $< -o $@

# The if statement prevents the libft Makefile clean rule being called twice
# if the rule is called from the fclean
clean:
	@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) .o files removal$(WHITE)"
	@make -C $(LIBFT_DIR) clean

fclean:
	@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_BIN) $(CLIENT_BIN) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)
	@echo "$(GREEN)✔ $(BLUE)$(USER_NAME)'s $(CODE) executables and .o files removal$(WHITE)"
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libft bonus

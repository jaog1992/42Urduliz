# Coder Alias
USER_NAME = jde-orma

# Compiler and flags
CC = gcc
CCFLAGS = -Wall -Wextra -Werror -fsanitize=address

# Directories
SRC_DIR = source/
INC_DIR = source/
LIBFT_DIR = libraries/libft/
OBJ_DIR = source/
BIN_DIR = ./

# Source files
SRC_FILE = push_swap_main.c push_swap_utilities.c push_swap_moves_push.c push_swap_moves_reverse.c push_swap_moves_rotate.c push_swap_moves_swap.c push_swap_sorting.c push_swap_quicksort.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILE))

# Binary name for your program
CODE_BIN = $(BIN_DIR)push_swap

# Static library
LIBFT = $(LIBFT_DIR)libft.a

# Output executable
NAME = push_swap

# Create the obj/ and bin/ directories if they don't exist
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Variable to control if the library has been built
LIBFT_BUILT = no

all: $(CODE_BIN)

$(CODE_BIN): $(LIBFT) $(OBJ)
	$(CC) $(CCFLAGS) -I$(INC_DIR) $(OBJ) -L$(LIBFT_DIR) -lft -o $@
	@echo "✔ $(USER_NAME)'s $(CODE_BIN) compilation"

$(LIBFT):
	@if [ "$(LIBFT_BUILT)" = "no" ]; then \
		make -C $(LIBFT_DIR); \
		LIBFT_BUILT=yes; \
	fi

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo "✔ $(USER_NAME)'s $(CODE_BIN) .o files removal"
	@make -C $(LIBFT_DIR) fclean

fclean: clean
	@$(RM) $(CODE_BIN)
	@echo "✔ $(USER_NAME)'s $(CODE_BIN) executable and .o files removal"
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

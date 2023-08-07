# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files and headers directories
SRC_DIR	= source/
INC_DIR	= include/

# Source files and headers
SRC_FILE = so_long_map.c so_long_utils.c so_long_error_check.c get_next_line.c get_next_line_utils.c
INC_FILE = get_next_line.h so_long.h

# Source files and headers complete path
SRC = $(addprefix $(SRC_DIR), $(SRC_FILE))
INC = $(addprefix $(INC_DIR), $(INC_FILE))

# Output executable
TARGET = so_long.out

# Build rule
$(TARGET): $(SRC) $(INC)
	$(CC) $(CFLAGS) $(SRC) -I$(INC_DIR) -o $(TARGET)

# Clean rule
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean


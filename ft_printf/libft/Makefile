# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 11:47:11 by jde-orma          #+#    #+#              #
#    Updated: 2023/02/09 04:06:19 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
## The name of the variable always starts with Uppercase.

## Executable name
NAME = libft.a

## gcc compilator execution flag
FLAG = -Wall -Wextra -Werror

## Directory to save the executable. ./ is the default
HDR = -I ./

## Source/name of the .c files to be compiled
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	  ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
	  ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	  ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c
## .o files are object type. They are output files for the compiler (result)
## and input files for the linker/librarian.
## When you compile a c file the compiler firstly creates object type files
## (Non executable machine code) and the it links them with the include
## functions to create the executable that can be interpreted by the CPU.

## Object files to be created
OBJ = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	  ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o ft_strlcpy.o \
	  ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o \
	  ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o ft_calloc.o \
	  ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o \
	  ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o \
	  ft_putendl_fd.o ft_putnbr_fd.o
## .a files are archive type. They are a set of .o file or static librarys
## and they are input files for the linker too.
## We use the "ar" command (archiver) to create the .a files.
##	-r -> If the .a of the library exists replaced it
##	-c -> If the .a does not exist create it
##	-s -> Creates an index 
## Rules start with lowercase. Their insides are written in the next line.
## If you type "make" on shell only the first rule will be executed.
## In this case we are using NAME to set the executable name
all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC) $(HDR)
	ar -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

## It erases all the .o files
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

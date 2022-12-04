# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-orma <jde-orma@42urduliz.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 11:47:11 by jde-orma          #+#    #+#              #
#    Updated: 2022/12/03 11:47:11 by jde-orma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
## Aldagaiaren izena hizki larrietan jartzen da.

## Nombre que queremos dar al ejecutable
NAME = libft.a

## Flag de ejecucion del compilador gcc
FLAG = -Wall -Wextra -Werror

## Direccion donde queremos que se cree el ejecutable. "./" es la por defecto
HDR = -I ./

## Compila todos los archivos .c
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c ft_toupper.c ft_strlen.c
## o fichero de tipo objeto. Para el compilador son archivos de salida (resultado) y par el linker/librarian de entrada
## Cuando compilas un programa c primero crea una serie de ficheros de tipo objeto (codigo máquina, pero no ejecutable) 
## y luego los enlaza mediante el linker (por ejemplo, cogiendo funciones de los includes). Esta serie de ficheros objeto
## enlazados crea el archivo de tipo ejecutable que la CPU puede interpretar. 
## https://pediaa.com/what-is-the-difference-between-object-file-and-executable-file/#:~:text=The%20main%20difference%20between%20object,%2C%20high%2Dlevel%20programming%20language.
OBJ = ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_tolower.o ft_toupper.o ft_strlen.o

##.a fichero de tipo archivo. on grupos de objetos (.o) o librerias estaticas y tambien son inputs del linker.
## Usamos el comando "ar" (arhivador) pra crear un archivo de tipo .a
##	-r -> Si el archivo de la libreria existe remplazalo por el nuevo
##	-c -> Si el archivo de la libreria no existe crealo
##	-s -> Crea un indexado 
## gcc $(FLAG) -o $(NAME) $(SRC)
##Arauen barneak hurrengo lerroan jartzen dira.
##"make" bakarrik jarrita shellen lehenengo araua soilik eragingo da.
##Kasu honetan NAME aldagaia ejekutablearen izena ezartzeko erabiltzen da
all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC) $(HDR)
	ar -rcs $(NAME) $(OBJ)
	ranlib $(NAME)

##.o artxibo guztiak kentzen ditu
clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

##a_araua:
##	echo $(TEXT)
##b_araua: a_araua
##	echo "B araua"
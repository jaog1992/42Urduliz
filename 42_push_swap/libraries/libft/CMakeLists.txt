cmake_minimum_required(VERSION 3.10)

project(libft)

# Directorio de código fuente de libft
set(LIBFT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/source")

# Agrega tus fuentes de libft al proyecto
file(GLOB LIBFT_SOURCES "${LIBFT_SOURCE_DIR}/*.c")

# Crea la biblioteca estática libft.a
add_library(libft STATIC ${LIBFT_SOURCES})

# Establece las rutas de salida
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

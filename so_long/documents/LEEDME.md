<h1 align="center">
	📖 so_long
</h1>

<p align="center">
	<b><i>Primera experiencia con librerias externas en C</i></b><br>

<h3 align="center">
	<a href="#%EF%B8%8F-about">Sobre</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Uso</a>
	<span> · </span>
	<a href="#-testing">Pruebas</a>
</h3>

---

## 💡 Sobre el proyecto

> _The aim of this project is to code a function that reads and returns a line from a file descriptor._

This project consists of coding a function that returns one line at a time from a text file.
After finishing this project, you will be familiar with:

### Reglas generales

- [x] Usar MiniLibX
- [x] Hacer un Makefile
- [x] Admitir como argumento un .ber

### Reglas del Juego
- [ ] The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.
- [ ] The W, A, S, and D keys must be used to move the main character.
- [ ] The player should be able to move in these 4 directions: up, down, left, right.
- [ ] The player should not be able to move into walls.
- [ ] At every move, the current number of movements must be displayed in the shell.
- [ ] You have to use a 2D view (top-down or profile).

### Reglas gestión gráficos
- [ ] Your program has to display the image in a window.
- [ ] The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- [ ] Pressing ESC must close the window and quit the program in a clean way.
- [ ] Clicking on the cross on the window’s frame must close the window and quit the
program in a clean way.
- [ ] The use of the images of the MiniLibX is mandatory.

### Reglas mapa
- [x] The map has to be constructed with 3 components: walls, collectibles, and free
space.
- [x] The map can be composed of only these 5 characters:
    - 0 for an empty space,
    - 1 for a wall,
    - C for a collectible,
    - E for a map exit,
    - P for the player’s starting position.
- [x]  The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.
- [x] The map must be rectangular.
- [x] The map must be closed/surrounded by walls. If it’s not, the program must return
an error.
- [x] You have to check if there’s a valid path in the map.
- [x] You must be able to parse any kind of map, as long as it respects the above rules.
- [x] If any misconfiguration of any kind is encountered in the file, the program must
exit in a clean way, and return "Error\n" followed by an explicit error message of
your choice.

## 🛠️ Usage

### Requirements

You will need a **`gcc` compiler** and the `unistd`, `stdlib`, `stdio` and `fcntl` standard **C libraries** to run it.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, use the Makefile or add the source files and the required flags

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## 📋 Testing

- [x] Francinette 100% 
- [ ] Francinette --strict NULL_CHECK.KO

You can uncomment and modify the main function on the get_next_line.c file.
The text files included on the "tests" directory are just examples, and are also to be modified.
Then you can use the makefile to compile it. Feell free to modify the BUFFER_SIZE on the FLAG to check if you understand how this affects the result and the performance of the code.

I recommend playing with the main function and also using this third party tester to fully test the project

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)

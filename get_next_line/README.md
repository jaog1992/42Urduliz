<h1 align="center">
	📖 get_next_line
</h1>

<p align="center">
	<b><i>How can we read a new line from a File descriptor?</i></b><br>
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/endpoint?url=https://api.github.com/repos/jaog1992/42Urduliz/contents/get_next_line&label=Code%20size&color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/endpoint?url=https://api.github.com/repos/jaog1992/42Urduliz/contents/get_next_line&label=Lines%20of%20code&color=critical" />
	<img alt="Code language count" src="https://img.shields.io/endpoint?url=https://api.github.com/repos/jaog1992/42Urduliz/contents/get_next_line&label=Languages&color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/endpoint?url=https://api.github.com/repos/jaog1992/42Urduliz/contents/get_next_line&label=Top%20language&color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/endpoint?url=https://api.github.com/repos/jaog1992/42Urduliz/commits?path=get_next_line&label=Last%20commit&color=green" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _The aim of this project is to code a function that reads and returns a line from a file descriptor._

	This project consists of coding a function that returns one line at a time from a text file. \n
	After finishing this project, you will be familiar with File descriptors and the open/read/close \n
	functions as well as with defining the correct BUFFER_SIZE for a given task. 


## 🛠️ Usage

### Requirements

You will need a **`gcc` compiler** and the 'unistd', 'stdlib', 'stdio' and 'fcntl' standard **C libraries** to run it.

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

You can uncomment and modify the main function on the get_next_line.c file.
The text files included on the "tests" directory are just examples, and are also to be modified.
Then you can use the makefile to compile it. Feell free to modify the BUFFER_SIZE on the FLAG to check if you understand how this affects the result and the performance of the code.

I recommend playing with the main function and also using this third party tester to fully test the project

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)
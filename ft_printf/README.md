<h1 align="center">
	📖 printf - (:exclamation: Ongoing)
</h1>

<p align="center">
	<b><i>How can we print variable values on the terminal?</i></b><br>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the project

> _The aim of this project is to code a function that emulates the behaviour of the stdio.h printf._

	This project consists of coding a function that is able to print the string value of a function
	variables on the terminal, on a similar way that the stdio printf does it.
	After finishing this project, you will be familiar with managament variable argument inputs.
 
 Implemented variable value convertions: **cspdiux%**:

Acronym  | Variable convertion
------------- | -------------
%c  | Chr
%s  | String
%p  | void * in hex format
%d  | Number in dec format
%i  | Integer in dec format
%u  | Unsigned Integer in dec format
%x  | Number in hex format in lowercase
%X  | Number in hex format in uppercase
%%  | Prints the '%' symbol


## 🛠️ Usage

### Requirements

You will need a **`gcc` compiler**, the `libft` functions and the `stdio` standard **C libraries** to run it and make tests.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include th header:

```C
#include "ft_printf.h"
```
**2. Compilation**

For compiling the code use the Makefile or add the source files and the required flags

```shell
gcc -Wall -Wextra -Werror <*.c files>
```

## 📋 Testing

I recommend uncommenting and playing with the main function and also using this third party tester to fully test the project

* [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)

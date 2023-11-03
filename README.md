# Shell


## Build Instructions
After entering the directory :
```
make
./shec_C
```

## Features
- Commands:
  - `echo` - Can take `[$ENV_VAR]` or `[custom_text]` as the argument.
  - `pwd`- Does not take any arguments. Prints the Current Working Directory.
  - `cd` - Takes the absolute path or the relative path as an argument.
  - `exit`  - Exits the shell.
  - `cd -` - Supports the last working directory.

All the `.c` files have a corresponding `.h` file (except `main.c`) which contain all the function declarations.



#### `cd.c`
Contatins the code for changing the present working directory in the shell.


#### `echo.c`
Contains the code print out the arguments passed in echo command. It supports the common environment variables as well - HOME, SHELL, PWD, USER, HOST.

#### `execute.c`
Contains all the code for executing the commands that haven't been explicitly coded i.e all except `cd`, `ls`, `pwd`, `echo`, etc. Also contains the code for executing the commands in background.

#### `header.h`
The header file that includes all the Library Inclusions at one place. By including this, there isn't a need to include the libraries again and again in every file.

#### `main.c`
Contains the main function and the basic functions used in the shell loop.

#### `prompt.c`
Contains code to send a prompt which has the username, hostname and the current working directory.

#### `pwd.c`
Contains the code to change the present working directory.

### `execute.c`
Contains the code for redirection and piping.

# Simple Shell Project

Welcome to our Simple Shell Project! This is a basic Unix-like shell implementation written in C.

## Description
Simple shell is a command language interpreter that executes commands read from the standard input or from a file, developed in C language. It emulates the operation of sh.

## Man page

You can see our man page for more explanations on how our simple shell works :
./man_1_simple_shell

## Prototype : int main (void);

## Table of Contents
- [Installation](#installation)
- [List of built-in commands](#list-of-built_in-commands)
- [Usage](#usage)
- [Functions used](#functions-used)
- [Features](#features)
- [Examples](#examples)
- [Exit Status](#exit-status)
- [Contributions](#contributions)
- [License](#license)
- [Flowchart](#flowchart)
- [Authors](#authors)
- [Acknowledgments](#acknowledgments)

## Installation
1. Clone this repository: `git clone git@github.com:NathalieMet/holbertonschool-simple_shell.git`
2. Compile the source code: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
3. Run the shell: `./hsh`

This repository contains all the code required for a custom function called simple shell. The simple shell function attempts to duplicate exactly the same process as the C sh function to a lesser extent. This project was carried out as part of Holberton School's learning program.

## List of built_in commands
Here is a list of our built-in commands
1. exit : Exit the shell
2. env : Displays the current environment

## Usage
This shell in interactive mode displays a prompt and wait for the user to type a command, then execute it if the command is found, or print an error message and display the prompt again. In non-interactive mode, it can exectute command that are passed to the program with a pipe operator. It supports basic commands.

## Functions used
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <features.h>

_getenv.c
check_dir_path.c
check_exit.c
display_prompt.c
execute_command.c
free_tokens.c
get_first_word.c
if_executable.c
interactive.c
is_it_empty.c
non_interactive.c
read_command.c
tokenize_command.c
main.h

## Features
- Basic command execution

## Examples
1. Run a program: `./my_program`
2. Execute a command and find the path: `ls -l`
3. Execute a command with a full pathname: `/bin/ls -l`
4. Execute a command in non-interactive mode : echo "/bin/ls" | ./hsh

## Exit Status
- **0**: Successful execution
- **1**: General error
- **2**: Incorrect usage
- **127**: Command not found (the specified command could not be located)

## Contributions
Contributions are welcome! Feel free to submit pull requests or report issues.

## License
This project is not currently licensed and is intended for educational purposes only. As a student project, it does not come with any licensing terms. Please be aware of the legal implications of using and distributing code without a proper license.

## Flowchart

![flowchart](https://github.com/NathalieMet/holbertonschool-simple_shell/blob/main/Diagramme%20sans%20nom.jpg)

## Authors
[AUTHORS] (./AUTHORS)

## Acknowledgments
Thanks to the open-source community for inspiration and guidance.

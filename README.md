# Simple Shell Project

Welcome to our Simple Shell Project! This is a basic Unix-like shell implementation written in C.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Features](#features)
- [Examples](#examples)
- [Exit Status](#exit-status)
- [Known Issues](#known-issues)
- [Contributions](#contributions)
- [License](#license)
- [Authors](#authors)
- [Acknowledgments](#acknowledgments)

## Installation
1. Clone this repository: `git clone git@github.com:NathalieMet/holbertonschool-simple_shell.git`
2. Compile the source code: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
3. Run the shell: `./hsh`

## Usage
This shell supports basic commands, process management, and redirection. Here are some examples:

- Run a command: `ls -l`
- Execute a program: `./my_program`
- Redirect output: `ls > output.txt`
- Chain commands: `ls | grep file`

## Features
- Basic command execution
- Background processes using `&`
- Input and output redirection with `>`, `<`
- Pipeline with `|`

## Examples
1. Run a program in the background: `./my_program &`
2. Redirect output to a file: `ls > files.txt`
3. Chain commands using a pipeline: `ls | grep keyword`

## Exit Status
- **0**: Successful execution
- **1**: General error
- **2**: Incorrect usage
- **127**: Command not found (the specified command could not be located)

## Known Issues
- Background processes might not always be cleaned up properly.

## Contributions
Contributions are welcome! Feel free to submit pull requests or report issues.

## License
This project is not currently licensed and is intended for educational purposes only. As an student project, it does not come with any licensing terms. Please be aware of the legal implications of using and distributing code without a proper license.

## Authors
- Nathalie Metreau [@NathalieMet](https://github.com/NathalieMet)
- Shane Vaudrey [@Shane35300](https://github.com/janesmith)

## Acknowledgments
Thanks to the open-source community for inspiration and guidance.

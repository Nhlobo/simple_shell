# Simple Shell Project

This is a simple shell implementation in C that supports basic shell functionalities such as executing commands, piping, file redirection, history, and more.

## Getting Started

To run the shell, compile all the source files using the following command:
```
gcc -o shell builtin_commands.c file_redirection.c main.c piping.c shell.c betty_would_be_proud.c history.c prompt.c
```

Then, run the compiled executable:
```
./shell
```

## Features

- Supports running commands with arguments
- Handles basic built-in commands like `cd`, `exit`, etc.
- Supports input/output redirection using `<` and `>`
- Implements piping of commands using `|`
- Keeps track of command history
- Includes "Betty Would Be Proud" feature for any input

## Usage

Once the shell is running, you can enter commands just like in a regular shell. Here are a few examples:
- `ls -l`: List files in the current directory
- `ls | sort`: Pipe output of `ls` command to `sort` command
- `cat file.txt > output.txt`: Redirect output of `cat` command to `output.txt`

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

### Simple Shell Project

This project involves creating a simple UNIX command-line interpreter, known as a shell. The shell allows users to interact with the operating system by executing commands. The implementation follows specific guidelines and includes various features.

#### Project Overview

The Simple Shell project challenges participants in the ALX School of Software Engineering to demonstrate their understanding of:

- Basics of programming
- Basics of C
- Thinking like an engineer
- Group work
- Learning how to learn

#### Project Tasks and Objectives

The project consists of several tasks, each building upon the previous ones. Here is an overview of the key tasks and their objectives:

1. **Betty would be proud**
   - Write code that passes the Betty checks, ensuring clean and readable code.

2. **Simple shell 0.1**
   - Write a UNIX command-line interpreter.
   - Display a prompt, wait for user input, and execute simple commands.
   - Handle errors, including the "end of file" condition.

3. **Simple shell 0.2**
   - Handle command lines with arguments.

4. **Simple shell 0.3**
   - Handle the PATH.
   - Avoid calling `fork` if the command doesn’t exist.

5. **Simple shell 0.4**
   - Implement the `exit` built-in to exit the shell.

6. **Simple shell 1.0**
   - Implement the `env` built-in to print the current environment.

7. **Simple shell 0.1.1**
   - Write a custom `getline` function, optimizing the use of the `read` system call.

8. **Simple shell 0.2.1**
   - Avoid using `strtok`.

9. **Simple shell 0.4.1**
   - Handle arguments for the built-in `exit`.

10. **setenv, unsetenv**
    - Implement the `setenv` and `unsetenv` built-in commands.

11. **cd**
    - Implement the `cd` built-in to change the current directory.

12. **;**
    - Handle the command separator `;`.

13. **&& and ||**
    - Handle the shell logical operators `&&` and `||`.

14. **alias**
    - Implement the `alias` built-in command.

15. **Variables**
    - Handle variables replacement, including `$?` and `$$`.

16. **Comments**
    - Handle comments (`#`).

17. **File as input**
    - Allow the shell to take a file as a command-line argument, containing commands to execute.

#### Compilation and Testing

- All code is compiled on Ubuntu 20.04 LTS using `gcc`.
- The shell should have the same output and error output as `/bin/sh`.
- Testing involves both interactive mode and non-interactive mode.

#### Allowed Functions and System Calls

- A specific list of functions and system calls is allowed for this project.

#### Requirements and Guidelines

- Follow specific coding style guidelines (Betty style).
- No memory leaks are allowed.
- Use system calls only when necessary.
- Maintain a clear project structure with documentation (README.md, AUTHORS, etc.).

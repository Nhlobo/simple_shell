# Unix Shell

This is a basic Unix shell implementation. It allows you to execute various commands such as listing directories, changing directories, displaying the current working directory, creating directories, removing files or directories, and reading file contents.

## Folder Description

- `execute.c`: This file contains the implementation of the `execute_command` function, which takes a command as input and executes the corresponding functionality.
- `shell.h`: This header file contains function declarations and necessary includes for the shell.
- `shell.c`: This is the main file of the shell. It contains the `main` function, which takes user input, executes the command, and repeats until the user exits.
- `Prompt.c`: This file contains the implementation of the `winning_team` function, which prints the shell prompt.
- `README.md`: This file provides information about the shell and its folder/file structure.


List of allowed functions and system calls
* chdir 
* close 
* closedir 
* Execve
* exit 
* _exit 
* fflush 
* fork 
* free 
* getcwd 
* getline 
* getpid 
* isatty 
* kill 
* malloc 
* open 
* opendir 
* perror 
* read 
* readdir 
* signal 
* stat 
* lstat 
* fstat 
* strtok 
* Wait
* Waitpid
* wait3 
* wait4 
* write 

## Additional Headers

The shell includes the following additional headers, depending on the functionality implemented for each command:

- `<unistd.h>`: Includes the necessary system calls for executing commands and changing directories.
- `<stdlib.h>`: Includes the necessary functions for memory management and string manipulation.
- `<string.h>`: Includes the necessary functions for string manipulation.
- `<sys/types.h>`: Includes the necessary data types for system calls.
- `<sys/stat.h>`: Includes the necessary functions and data types for file and directory manipulation.
- `<dirent.h>`: Includes the necessary functions and data types for directory manipulation.

## Error Handling and Validation Checks

The shell includes error handling and validation checks for various scenarios, such as invalid commands, missing arguments, and file/directory existence checks. Error messages are displayed to the user when necessary.

## Usage

To use the shell, compile the source files using a C compiler and run the resulting executable. The shell will display a prompt where you can enter commands. Use the following commands:

- `listdir`: Lists the contents of the current directory.
- `nav [directory]`: Changes the current directory to the specified directory.
- `showdir`: Displays the current working directory.
- `createdir [directory]`: Creates a new directory with the specified name.
- `erase [path]`: Removes the file or directory at the specified path.
- `read [file]`: Reads and displays the contents of the specified file.


## Example

Here's an example of using the shell:

```
$ ./shell
why? listdir
file1.txt
file2.txt
folder1
folder2
why? nav folder1
why? showdir
Current directory: /home/user/shell/folder1
why? createdir new_folder
why? listdir
file1.txt
file2.txt
folder2
new_folder
why? erase new_folder
why? listdir
file1.txt
file2.txt
folder2
why? read file1.txt
Contents of file1.txt:
Hello, world!
why? exit
$


## AUTHOR
This file list all contributors of the repository

Novice Mathebula <nhlobo365@gmail.com>
NOUAMA1

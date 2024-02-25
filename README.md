# Unix Shell

This is a basic Unix shell implementation allowing users to execute various commands. Functionalities include listing directories, changing directories, displaying the current working directory, creating directories, removing files or directories, and reading file contents.

## Folder Description

- **execute.c:** Implementation of the `execute_command` function, which executes the corresponding command.
- **shell.h:** Header file with function declarations and necessary includes.
- **shell.c:** Main file containing the `main` function for user input, command execution, and repeated processing.
- **prompt.c:** Implementation of the `winning_team` function, which prints the shell prompt.
- **README.md:** Information about the shell, folder/file structure, and usage.

## List of Allowed Functions and System Calls

The shell uses the following functions and system calls:

- `chdir`, `close`, `closedir`, `execve`, `exit`, `_exit`, `fflush`, `fork`, `free`, `getcwd`, `getline`, `getpid`, `isatty`, `kill`, `malloc`, `open`, `opendir`, `perror`, `read`, `readdir`, `signal`, `stat`, `lstat`, `fstat`, `strtok`, `wait`, `waitpid`, `wait3`, `wait4`, `write`.

## Additional Headers

Additional headers are included based on the implemented functionality:

- `<unistd.h>`: For system calls related to executing commands and changing directories.
- `<stdlib.h>`: For memory management and string manipulation functions.
- `<string.h>`: For string manipulation functions.
- `<sys/types.h>`: For data types used in system calls.
- `<sys/stat.h>`, `<dirent.h>`: For file and directory manipulation functions.

## Error Handling and Validation Checks

The shell includes error handling and validation checks for scenarios like invalid commands, missing arguments, and file/directory existence checks. Error messages are displayed to the user when needed.

## Usage

Compile the source files with a C compiler and run the resulting executable. The shell will display a prompt for entering commands. Example commands:

- `listdir`: Lists the contents of the current directory.
- `nav [directory]`: Changes the current directory to the specified directory.
- `showdir`: Displays the current working directory.
- `createdir [directory]`: Creates a new directory with the specified name.
- `erase [path]`: Removes the file or directory at the specified path.
- `read [file]`: Reads and displays the contents of the specified file.

## Example

Example of using the shell:

```shell
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

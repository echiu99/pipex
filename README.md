# Pipex
Pipex is a project I developed to replicate the functionality of a shell pipeline. It allows you to redirect input and output through a series of commands, just like the shell syntax < file1 cmd1 | cmd2 > file2. The project dives into Unix system calls and teaches the fundamentals of inter-process communication using pipes.

## Features
- Executes two shell commands in sequence, redirecting the output of the first command as the input to the second.
- Handles file reading and writing to simulate shell redirections.
- Implements error handling for invalid files, commands, or other unexpected behaviors.

## Installation
1. Clone the repository:
```
git clone https://github.com/your-username/pipex.git  
cd pipex  
```
2. Compile the program using the Makefile:
```
make  
```

## Usage
Run the program using the following syntax:
```
./pipex file1 "cmd1" "cmd2" file2
```
- file1: Input file.
- cmd1: First shell command to execute.
- cmd2: Second shell command to execute.
- file2: Output file where the result will be written.

The program replicates the behavior of the shell command:
```
< file1 cmd1 | cmd2 > file2  
```

### Examples
1. Count the number of lines in a file:
```
./pipex infile "cat -e" "wc -l" outfile
```
This behaves like:
```
< infile cat -e | wc -l > outfile  
```
2. Search for a pattern in a file and count the words:
```
./pipex infile "grep pattern" "wc -w" outfile  
```
This behaves like:
```
< infile grep pattern | wc -w > outfile
```

## Key Features
- Inter-process Communication: I implemented the Unix pipe() system call to pass data between commands.
- File Redirection: Used file descriptors to simulate input (<) and output (>).
- Error Handling: Ensures no crashes or undefined behavior occur. Gracefully handles invalid files, commands, and other edge cases.
- Memory Management: All dynamically allocated memory is freed properly to prevent memory leaks.

## Technical Details
- Programming Language: C.
- Libraries/Functions Used:
  - Unix system calls: pipe, fork, execve, dup2, waitpid, etc.
  - File handling: open, read, write, close.
  - Custom functions from my libft for string handling and utility functions.
- Makefile Rules:
  - make: Compile the program.
  - make clean: Remove object files.
  - make fclean: Remove object files and the executable.
  - make re: Recompile everything.

## Challenges
Building this project required a deep understanding of Unix system calls and their interactions. Handling edge cases like invalid commands, file permissions, or incomplete pipes was an excellent opportunity to enhance my debugging skills and understanding of process communication.

## About This Project
I developed Pipex to explore and deepen my knowledge of how the Unix shell works under the hood. Every aspect of the project, from parsing commands to setting up pipes and managing processes, was implemented by me. This project solidified my understanding of core Unix concepts and provided a strong foundation for future projects involving system-level programming.

## Acknowledgments:
This project is part of the 42 curriculum and is designed to teach the fundamentals of threading, synchronization, and process management. Special thanks to the 42 network for the learning opportunity.

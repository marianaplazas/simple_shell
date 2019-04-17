# Simple Shell

Simple UNIX command line interpreter based on the DASH shell. It understands basic UNIX commands from the standard input or file. It's not necessary to type the complete path of an executable file, since the shell can find it. It also  and has a built-in exit.

## General purposes

* How does a shell work
* What is a pid and a ppid
* How to manipulate the environment of the current process
* What is the difference between a function and a system call
* How to create processes
* What are the three prototypes of main
* How does the shell use the PATH to find the programs
* How to execute another program with the execve system call
* How to suspend the execution of a process until one of its children terminates
* What is EOF / end-of-file? 

## Features

* Displays a prompt and waits for the user to type a command. A command line always end with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines can have arguments.
* It handles the path of an executable and doesn't require typing it.
* If an executable cannot be found, print an error message and display the prompt again.
* Handles errors.
* It handles the "end of file" condition (Ctrl+D)
* Has an exit built-in, that exits the shell.
* Added env built-in that prints the current environment.

## What it does?

A prompt is displayed to move the user to write a command to be interpreted. It searches for the PATH in the environment variable and tthen for the specific absolute path inside it. Then it executes the file in a child process to protect the current process.

## Basic comands

*ls
List all files in the current directory

*pwd
shows all path 

*cat 
concatenate files and print on the standard output
## compilation mod

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
##execute 
```bash
./hsh
```
or 
```bas
echo "command" | ./hsh
```
## Authors

Miguel Antonio Cortés Muñoz, Mariana Plazas



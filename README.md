# Mini Unix shell

## Project Overview
### Description
A replica of the Unix shell of the Linux Operating System.

### Purpose
Replicate the original Unix shell from the ground up for exploratory purposes.

### Key features and highlights
1. Prompt text is colored for visual appeal.
2. Can execute the following commands:
- ls
- pwd
- whoami
- date
- echo
- grep
- exit

## Table of Contents
(coming soon)

## Getting Started

# Prerequisites
1. Linux OS / Ubuntu on Windows
- This program only works on Linux. If you use Windows, you can download Ubuntu for Windows.
2. GCC Compiler
- Coding in C requires the GCC compiler.

## Usage
Upon cloning, type 'make' in the directory of the folder and you will see a "main" executable file.

Type ./main in the same directory to launch the shell.

## Built-in commands

As of right now, the shell mostly operates from calling the main shell (as seen in the execvp() command in [executor.c](src/executor.c)).

This shell will soon have its own built-in shell commands.

## Authors and credits
Just me, with the help of AI and the internet.
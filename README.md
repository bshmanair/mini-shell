# Mini Unix shell

## Project Overview
### Description
A replica of the Unix shell of the Linux Operating System.

### Purpose
Replicate the original Unix shell from the ground up for exploratory purposes.

### Key features and highlights
1. Prompt text is colored for visual appeal.
2. Can execute the following commands:\
[placeholder]

## Getting Started

You can find the documentation [here](docs/), with explanations for each file.

# Prerequisites
1. [Linux OS / Ubuntu on Windows](https://ubuntu.com/desktop/wsl)
- This program only works on Linux. Click on the link for more information about installing Ubuntu on your respective OS.
2. GCC Compiler
- Coding in C requires the GCC compiler.
- You can install GCC on Linux by typing the following on your terminal:

    ```
    sudo apt install gcc
    ```

## Usage
Upon cloning, type the command 'make' in the directory of the folder and you will see a "main" executable file.

Then type ./main in the same directory to launch the shell.

## Built-in commands

As of right now, the shell mostly operates from calling the main shell (as seen in the execvp() command in [executor.c](src/executor.c)).

This shell will soon have its own built-in shell commands.

## Authors and credits
Just me, with the help of AI and the internet.
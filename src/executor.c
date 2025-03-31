#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../include/executor.h"

void execute(char **tokens)
{
    pid_t pid = fork();

    if (pid == 0) // Child process
    {
        execvp(tokens[0], tokens);
        perror("my-shell");
        exit(1);
    }
    else if (pid > 0) // Parent process
    {
        wait(NULL);
    }
    else if (pid < 0) // Scenario: fork failed
    {
        perror("Fork failed");
    }
}

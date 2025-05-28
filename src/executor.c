#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../include/executor.h"

void execute(char **tokens)
{
    if(tokens[0] == NULL || strlen(tokens[0]) == 0)
    {
        
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        execvp(tokens[0], tokens);
        perror("my-shell");
        exit(1);
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
    else
    {
        perror("Fork failed");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "../include/executor.h"
#include "../include/helper.h"

void execute(char **tokens, char *input, size_t tokenCount)
{
    if (strcmp(tokens[0], "exit") == 0)
    {
        return;
    }
    if (tokens[0] == NULL || strlen(tokens[0]) == 0)
    {
        free_tokens(tokens);
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        // TODO: De-wrap shell
        if (strcmp(tokens[0], "cd") == 0)
        {
            system(input);
        }
        else
        {
            system(input);
        }
        perror("my-shell"); // for debugging
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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <assert.h>
#include <pwd.h>
#include "../include/executor.h"
#include "../include/helper.h"

void execute(char **tokens)
{
    // Edge cases
    if (tokens[0] == NULL || strlen(tokens[0]) == 0)
    {
        free_tokens(tokens);
    }

    // Stuff that shouldn't get in pid_t mess...
    if (strcmp(tokens[0], "exit") == 0)
    {
        return;
    }

    if (strcmp(tokens[0], "cd") == 0)
    {
        if (tokens[1] == NULL) // need to have autoconversion from ~ or ~/
        {
            char *path = "/home/";
            strcat(path, getpwuid(getuid()));
            if (chdir(path) != 0)
            {
                perror("cd error");
                exit(1);
            }
            else
            {
                printf("Changed directory to %s\n", path);
                return 0;
            }
        }
        else
        {
            if (chdir(tokens[1]) != 0)
            {
                perror("cd error");
                exit(1);
            }
            else
            {
                char *cwd = getcwd(NULL, 0);
                printf("Changed directory to: %s\n", cwd);
                free(cwd);
            }
            return;
        }
    }

    pid_t pid = fork();

    if (pid == 0)
    {
        // TODO: De-wrap shell
        execvp(tokens[0], tokens);
        // perror("my-shell"); // for debugging
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
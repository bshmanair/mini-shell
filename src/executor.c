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
        return;
    }

    if (strcmp(tokens[0], "cd") == 0)
    {
        if (tokens[1] == NULL) // need to have autoconversion from ~ or ~/
        {
            struct passwd *pw = getpwuid(getuid());
            if (pw == NULL)
            {
                perror("getpwuid failed");
                return;
            }
            const char *home = pw->pw_dir;
            if (chdir(home) != 0)
            {
                perror("cd error");
                exit(1);
            }
            else
            {
                printf("Changed directory to %s\n", home);
            }
            return;
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

    char *bash_cmd = rejoin(tokens);
    pid_t pid = fork();

    if (pid == 0)
    {
        char *args[] = {"bash", "-c", bash_cmd, NULL};
        execvp("bash", args);
        // perror("execvp failed"); // for debugging
        exit(1);
    }
    else if (pid > 0)
    {
        wait(NULL);
        free(bash_cmd);
    }
    else
    {
        perror("Fork failed");
        free(bash_cmd);
    }
}
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "../include/executor.h"
#include "../include/parser.h"
#include "../include/helper.h"
#include "../include/init.h"

int main(void)
{
    init_shell();
    char *input = NULL;
    size_t input_len = 0;
    char *path;
    char **tokens;
    while (1)
    {
        path = getcwd(NULL, 0);
        if (path != NULL)
        {
            printf("\nYou are currently in: %s\n", path);
            free(path);
        }
        else
        {
            perror("getcwd error");
        }

        printf("Enter prompt: ");
        if (getline(&input, &input_len, stdin) == -1)
        {
            printf("End of file detected. Exiting...\n");
            break;
        }

        tokens = parse(input);
        if (tokens[0] != NULL)
        {
            execute(tokens);
        }
    }

    printf("\n\n\nShell terminated. Exiting...\n\n\n");

    for (int i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }
    free(tokens);

    free(input);
    return 0;
}
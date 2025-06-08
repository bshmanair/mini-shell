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
    char *path = NULL;
    char **tokens = NULL;
    size_t input_len = 0;
    do
    {
        // Prompt display
        path = getcwd(NULL, 0);
        if (path != NULL)
        {
            printf("\e[31m\nYou are currently in: %s\n\e[0m", path);
            free(path);
        }
        else
        {
            perror("getcwd error");
        }

        // User enters prompt
        printf("\e[31mEnter prompt: \e[0m");
        if (getline(&input, &input_len, stdin) == -1)
        {
            printf("End of file detected. Exiting...\n");
            break;
        }

        // Parsing stage
        tokens = parse(input);
        if (tokens[0] != NULL)
        {
            execute(tokens, input, strlen(input)); // TODO: Fix execute() parameter passing
        }
    } while (strcmp(tokens[0], "exit") != 0);

    printf("\n\n\nShell terminated. Exiting...\n\n\n");

    for (int i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }
    free(tokens);

    free(input);
    return 0;
}
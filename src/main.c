#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/executor.h"
#include "../include/parser.h"
#include "../include/helper.h"
#include "../include/init.h"

int main(void)
{
    char *input = NULL;
    char **tokens = NULL;
    size_t input_len = 0;

    init_shell();

    while (1)
    {
        printf("\e[31mMVP Shell > \e[0m");
        if (getline(&input, &input_len, stdin) == -1)
        {
            printf("\nEOF received. Exiting...\n");
            break;
        }

        tokens = parse(input);
        if (tokens == NULL || tokens[0] == NULL)
        {
            free_tokens(tokens);
            continue;
        }

        if (strcmp(tokens[0], "exit") == 0)
        {
            free_tokens(tokens);
            break;
        }

        execute(tokens);
        free_tokens(tokens);
    }

    free(input);
    printf("Shell terminated. Exiting...\n");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tokenizer.h"
#include "../include/executor.h"

char **tokenize(char *input)
{
    int token_count = 1;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
        {
            token_count++;
        }
    }
    char **tokens = malloc(sizeof(char *) * (token_count + 1));
    if (tokens == NULL)
        print_malloc_error();

    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL)
    {
        tokens[i] = strdup(token);
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;

    return tokens;
}

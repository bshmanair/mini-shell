#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tokenizer.h"
#include "../include/executor.h"

char **tokenize(char *input)
{
    int token_count = 1;
    for (int i = 0; input[i + 1] != '\0'; i++)
    {
        if (input[i] == ' ' && input[i + 1] != ' ')
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
        tokens[i++] = strdup(token);
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;
    return tokens;
}

void free_tokens(char **tokens)
{
    for (int i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }
    free(tokens);
}

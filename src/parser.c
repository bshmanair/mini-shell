#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/parser.h"

char **parse(char *input)
{
    input[strcspn(input, "\n")] = '\0';
    int token_count = 1;
    for (int i = 0; input[i + 1] != '\0'; i++)
    {
        if (input[i] == ' ' && input[i + 1] != ' ')
        {
            token_count++;
        }
    }

    char **tokens = (char **)malloc(sizeof(char *) * (token_count + 1));
    if (tokens == NULL)
    {
        printf("Malloc error");
        return NULL;
    }

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
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/helper.h"

void free_tokens(char **tokens)
{
    for (int i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }
    free(tokens);
}

// rejoin tokens together
char *join(char **tokens)
{
    char *joined = NULL;
    for (int i = 0; tokens[i] != NULL; i++)
    {
        char *temp;
        if (joined == NULL)
        {
            asprintf(&joined, "%s", tokens[i]);
        }
        else
        {
            asprintf(&temp, "%s %s", joined, tokens[i]);
            free(joined);
            joined = temp;
        }
    }
    return joined;
}
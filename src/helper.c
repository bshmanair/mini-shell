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

char *substring(const char *src, int start, int length) // MUST BE USED IN A VARIABLE OTHERWISE MEMORY LEAK
{
    if (start < 0 || length < 0 || start + length > strlen(src))
    {
        return NULL;
    }
    char *sub = (char *)malloc(length + 1);
    if (!sub)
    {
        return NULL;
    }
    strncpy(sub, src + start, length);
    sub[length] = '\0';
    return sub;
}
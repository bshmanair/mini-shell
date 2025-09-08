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
char *rejoin(char **tokens)
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
    char *sub = malloc(length + 1);
    if (!sub)
    {
        return NULL;
    }
    strncpy(sub, src + start, length);
    sub[length] = '\0';
    return sub;
}

char *merge(char *a, char *b)
{
    int len = (int)(strlen(a) + strlen(b));
    int len1 = (int)strlen(a);
    int len2 = (int)strlen(b);
    char *new = malloc(len * sizeof(char) + 1);
    for (int i = 0; i < len1; i++)
    {
        new[i] = a[i];
    }
    for (int i = 0; i < len2; i++)
    {
        new[len1 + i] = b[i];
    }
    new[len] = '\0';
    return new;
}

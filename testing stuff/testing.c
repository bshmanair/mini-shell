#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 20

int main()
{
    char **strings = NULL;
    int size = 5;

    strings = (char **)malloc(size * sizeof(char *));
    if (strings == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        strings[i] = (char *)malloc((MAX_STRING_LENGTH + 1) * sizeof(char));
        if (strings[i] == NULL)
        {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
        sprintf(strings[i], "Student%d", i);
    }

    for (int i = 0; i < size; i++)
        printf("%s\n", strings[i]);

    for (int i = 0; i < size; i++)
        free(strings[i]);

    free(strings);
    return 0;
}
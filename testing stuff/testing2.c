#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[] = "ls -l /home/user";
    char token = strtok(input, " "); // points to first token
    char **tokens = NULL;

    // Check number of tokens
    int token_count = 1;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == ' ')
            token_count++;
    }
    // Allocates memory for each token element in token array
    for (int i = 0; i < token_count; i++)
    {
        while (token != NULL)
        {
            size_t token_size = strlen(token);
            tokens[i] = (char *)malloc(sizeof(char) * token_size);
            tokens[i] = token;
            token = strtok(input, " "); // pointer shifts to next token
        }
    }
    return 0;
}
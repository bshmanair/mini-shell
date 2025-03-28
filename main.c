#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "DynamicArrays.h"
#include "DynamicArrays.c"

int main()
{
    char input[100] = "";
    char **tokens = NULL;
    do
    {
        /*
        \033[0;31m <--- start of red

        \033[0m <--- resets colors
        */
        printf("\033[0;31mmini-shell>\033[0m "); // input
        fgets(input, 100, stdin);                // accept first 100 characters
        input[strcspn(input, "\n")] = '\0';      // remove trailing newline character

        // now making token array
        char token = strtok(input, " "); // Points to first token
        char **tokens = NULL;

        // Establish no. of tokens
        int token_count = 1;
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (input[i] == ' ')
                token_count++;
        }

        // Allocate memory then assign each token element in token array
        for (int i = 0; i < token_count; i++)
        {
            while (token != NULL)
            {
                size_t token_size = strlen(token);
                tokens[i] = (char *)malloc(sizeof(char) * token_size);
                tokens[i] = token;
                token = strtok(input, " ");
            }
        }
        // Getting first command
        char first[100] = "";
        for (int i = 0; input[i] != ' ' || input[i] != '\0'; i++)
        {
            first[i] = input[i];
        }

        // Process management
        pid_t process_id = fork();
        if (process_id == 0) // Child process
            execvp(first, tokens);
        else
            break;
    } while (strcmp(input, "exit") != 0);

    printf("\nProgram executed, exiting...\n");
    return 0;
}
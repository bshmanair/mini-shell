#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int token_count = 0;
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
        char *token = strtok(input, " "); // Points to first token

        // Establish no. of tokens (just determine the number of spaces and add 1)
        token_count = 1;
        for (int i = 0; input[i] != '\0'; i++)
        {
            if (input[i] == ' ')
                token_count++;
        }
        tokens = malloc(token_count * sizeof(char *)); // Allocate memory to the main token array

        // Allocate memory then assign each token element in token array
        int i = 0;
        while (token != NULL && i < token_count)
        {
            size_t token_size = strlen(token);
            tokens[i] = strdup(token); // Creates a copy of the token string and puts it in the tokens array
            token = strtok(NULL, " "); // Cycling through the tokens through space delimiter
            i++;
        }
        tokens[i] = NULL;

        // Process management
        pid_t process_id = fork();
        if (process_id == 0) // Child process
            execvp(tokens[0], tokens);
        else
            wait(NULL);

        // Freeing all tokens
        for (int i = 0; i < token_count; i++)
            free(tokens[i]); // Free each token string space
        free(tokens);        // Free the array of tokens
    } while (strcmp(input, "exit") != 0);

    printf("\nProgram executed, exiting...\n");
    return 0;
}
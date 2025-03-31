#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    char input[1024];
    char **tokens;

    do
    {
        printf("my-shell $ ");
        // Edge case: User presses CTRL+D (check on the spot)
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\n");
            break;
        }
        input[strcspn(input, "\n")] = '\0';
        tokens = tokenize(input);

        // Edge case: User didn't put anything
        if (tokens[0] != NULL)
        {
            execute(tokens);
        }

        free_tokens(tokens);

    } while (strcmp(input, "exit") != 0);

    return 0;
}

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

void execute(char **tokens)
{
    pid_t pid = fork();

    if (pid == 0) // Child process
    {
        execvp(tokens[0], tokens);
        perror("my-shell");
        exit(1);
    }
    else if (pid > 0) // Parent process
    {
        wait(NULL);
    }
    else if (pid < 0) // Scenario: fork failed
    {
        perror("Fork failed");
    }
}

void free_tokens(char **tokens)
{
    for (int i = 0; tokens[i] != NULL; i++)
    {
        free(tokens[i]);
    }
    free(tokens);
}

void print_malloc_error()
{
    perror("malloc");
    exit(EXIT_FAILURE);
}
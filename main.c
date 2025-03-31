#include <stdio.h>
/**
 * Used:
 * - fgets()
 * - perror()
 */
#include <stdlib.h>
/**
 * Used:
 * - malloc()
 * - free()
 */

#include <string.h>
/**
 * Used:
 * - strcmp()
 * - strcspn()
 * - strcpy()
 * - strlen()
 */
#include <unistd.h>
/**
 * Used:
 * - fork()
 * - execvp()
 */
#include <sys/wait.h>
/**
 * Used:
 * - wait()
 * - waitpid()
 */
#include <sys/types.h>
/**
 * Used:
 * - pid_t (datatype)
 */

// Functions list
char **tokenize(char *input);
void execute(char **tokens);

int main()
{
    char input[1024];
    char **tokens;

    do
    {
        printf("my-shell $ ");
        fgets(input, 1024, stdin);
        input[strcspn(input, "\n")] = '\0';
        tokens = tokenize(input);

        // Edge case: User didn't put anything
        if (tokens[0] != NULL)
        {
            execute(tokens);
        }

        // Freeing memory to prevent memory leak
        for (int i = 0; tokens[i] != NULL; i++)
        {
            free(tokens[i]);
        }
        free(tokens);

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
    if (tokens == NULL) //
    {
        printf("Memory allocation failed");
        return 1;
    }

    char *token = strtok(input, " ");
    int i = 0;
    while (token != NULL)
    {
        int size = strlen(token);
        tokens[i] = malloc((size + 1) * sizeof(char));
        if (tokens[i] == NULL)
        {
            printf("Memory allocation failed");
            return 1;
        }
        strcpy(tokens[i], token);
        i++;
        token = strtok(NULL, " ");
    }
    tokens[i] = NULL;

    return tokens;
}

void execute(char **tokens)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        execvp(tokens[0], tokens);
        printf("Child process failed to run");
        exit(1);
    }
    else if (pid > 0)
    {
        wait(NULL);
    }
    else if (pid < 0)
    {
        perror("Fork failed");
    }
}
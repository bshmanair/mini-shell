#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tokenizer.h"
#include "../include/executor.h"

int main()
{
    char input[1024];
    char **tokens;

    do
    {
        printf("my-shell $ ");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';
        tokens = tokenize(input);

        if (tokens[0] != NULL)
        {
            execute(tokens);
        }

        free_tokens(tokens);

    } while (strcmp(input, "exit") != 0);

    return 0;
}

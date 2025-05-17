#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/tokenizer.h"
#include "../include/executor.h"
#include "../include/init_shell.h"

int main()
{
    char input[1024];
    char **tokens;

    init_shell();

    do
    {
        printf("\033[0;31mmy-shell $ \033[0m");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
        {
            exit(EXIT_SUCCESS);
        }

        tokens = tokenize(input);

        if (tokens[0] != NULL)
        {
            execute(tokens);
        }

        free_tokens(tokens);

    }
    while (strcmp(input, "exit") != 0);

    return 0;
}

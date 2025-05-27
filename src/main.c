#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    char *input = NULL;
    size_t input_len = 0;
    char *path;
    while(1)
    {
        path = getcwd(NULL,0);
        if (path != NULL)
        {
            printf("\nYou are currently in: %s\n",path);
            free(path);
        }
        else
        {
            perror("getcwd error");
        }

        
        printf("Enter prompt: ");
        if (getline(&input,&input_len,stdin) != -1)
        {
            printf("End of file detected. Exiting...\n");
            break;
        }
               
        input[0] = '\0';
        //TODO: Make a tokenizer
        printf("%s\n",input);
    }

    printf("\n\n\nShell terminated. Exiting...\n\n\n");

    free(input);
    return 0;
}
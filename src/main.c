#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    char *input = NULL;
    size_t input_len = 0;
    char *path;
    do
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
            input[strcspn(input,"\n")] = '\0';
        }
        else if (input)
        {
            input[0] = '\0';
        }
        printf("%s\n",input);
        printf("%ld\n",input_len);
    }
    while(strcmp(input,"exit") != 0);
    printf("\n\n\nShell terminated. Exiting...\n\n\n");

    free(input);
    free(path);
    return 0;
}
#define _GNU_SOURCE //linux-exclusive dynamic buffer resizing -> getline()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *input = NULL; //reasonable 1024 bytes acce
    size_t input_len = 0;
    do
    {
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

    }
    while(strcmp(input,"exit") != 0);
    printf("\n\n\nShell terminated. Exiting...\n\n\n");

    free(input);
    return 0;
}
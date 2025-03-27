#include <stdio.h>
#include <string.h>
int main()
{
    char input[100] = "";
    do
    {
        printf("mini-shell>");
        fgets(input, 100, stdin);           // accept first 100 characters
        input[strcspn(input, "\n")] = '\0'; // remove trailing newline character
    } while (strcmp(input, "exit") != 0);
    return 0;
}
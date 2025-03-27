#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    // for fork()
#include <sys/types.h> // for pid_t

int main(int argc, char *argv[])
{
    pid_t id = fork();
    // printf("Hello world from id: %d\n", id);
    if (id == 0)
        printf("ID of child process = %d\n", id);
    else
        printf("ID of parent process = %d\n", id);
    return 0;
}
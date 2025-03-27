#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    // for fork()
#include <sys/types.h> // for pid_t
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    char *args[] = {"ls", NULL};
    if (pid == 0)
    {
        // Child process code
        execvp("ls", args); // replace child process with "ls"
    }
    else
    {
        // Parent process code
        wait(NULL); // Wait for child to finish
        printf("Child process has finished.\n");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    // for fork()
#include <sys/types.h> // for pid_t
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    _execl(
        "C:\\Windows\\System32\\ping.exe",
        "C:\\Windows\\System32\\ping.exe",
        "google.com",
        NULL);
}
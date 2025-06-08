#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#define clearscreen() printf("\033[H\033[J")

void init_shell()
{
    struct termios oldt, newt;
    int ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    clearscreen();
    char *username = getenv("USER");
    printf("Username: %s\n", username);
    printf("\nPress any key to continue...\n");

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}
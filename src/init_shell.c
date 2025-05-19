#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#define clearscreen(void) printf("\033[H\033[J")

void init_shell(void)
{
    struct termios oldt, newt;
    int ch = 0;

    tcgetattr(STDIN_FILENO,&oldt);
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW, &newt);

    clearscreen(void);
    char* username = getenv("USER");
    printf("Your username is: %s\n",username);
    printf("\nPress any key to continue...\n");

    ch = getchar();

    tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
}
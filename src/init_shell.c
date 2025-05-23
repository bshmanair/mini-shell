/**
 * @file        init_shell.c
 * @brief       Shell initialization routines for the mini shell project.
 * @author      Bheeshma Nair
 * @date        2025-05-23
 * @details     Provides the init_shell() function, which configures the terminal
 *              for shell use, greets the user, and restores terminal settings.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <termios.h>

 /**
  * @brief Clears the terminal screen using ANSI escape codes.
  */
 #define clearscreen() printf("\033[H\033[J")
 
 /**
  * @brief  Prepares the terminal for shell use and greets the user.
  *
  * This function:
  *   - Disables line buffering and input echoing in the terminal.
  *   - Clears the screen.
  *   - Prints the current username.
  *   - Waits for the user to press any key.
  *   - Restores original terminal settings.
  *
  * @note   Modifies terminal settings and prints to stdout. Settings are set back to default after usage.
  */
 void init_shell(void)
 {
     struct termios oldt, newt;
     int ch = 0;
 
     tcgetattr(STDIN_FILENO, &oldt);
     newt = oldt;
 
     newt.c_lflag &= ~(ICANON | ECHO);
     tcsetattr(STDIN_FILENO, TCSANOW, &newt);
 
     clearscreen();
     char* username = getenv("USER");
     printf("Your username is: %s\n", username);
     printf("\nPress any key to continue...\n");
 
     ch = getchar();
 
     tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
     clearscreen();
 }
 
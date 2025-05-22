The shell initializer clears the screen before printing the user's name (generally 'root') and prompting the user to enter a key to launch the shell.

The termios.h library serves to be useful here because I was able to modify the terminal's "canonical mode", which is a mode where the read request will not return until a full line is typed or a signal is recieved, which in this case is by default the ENTER key.

But since I want the terminal to accept any key to launch the shell prompt, termios.h helps me temporarily change the terminal's input/output behavior. This is seen in the line:

```
newt.c_lflag &= ~(ICANON | ECHO);
```

ICANON is the canonical mode flag that makes the terminal wait for Enter before sending input to the program.

ECHO is the state that determines whether the characters typed in the terminal are visible or not.

This line sets both macro flags to 0, so during this temporary modification, the user's typing isn't visible in the terminal and they may enter any key for the program to continue.

The terminal is then restored to normal after.
## 🐚 Bash Wrapper Shell in C

A lightweight, interactive shell implemented in C that wraps user commands by forwarding them to `bash -c`. It supports essential shell features like `cd`, command chaining, piping, redirection, background jobs, and graceful exit handling.

---

### 📦 Features

* Interactive prompt with customizable color
* Built-in `cd` command
* Support for pipes (`|`), redirection (`>`, `<`), and command chaining with semicolons (`;`)
* Handling of quoted strings and background jobs (`&`)
* Graceful handling of `Ctrl+D` (EOF) and clean shell termination
* Modular, maintainable C codebase

---

### 🗂️ File Structure

```
.
├── main.c            # Main input loop and shell initialization
├── executor.c        # Command execution logic
├── parser.c          # Input parsing and tokenization
├── helper.c          # Utility functions for strings and tokens
├── init.c            # Shell initialization and terminal settings
├── include/          # Header files for modularity
│   ├── executor.h
│   ├── parser.h
│   ├── helper.h
│   └── init.h
```

---

### 🔧 Build and Run

```bash
gcc main.c executor.c parser.c helper.c init.c -o myshell
./myshell
```

---

### 🧪 Tested Features

* Execution of external commands and built-ins like `cd`
* Command pipelines and chaining
* Input/output redirection
* Background job execution
* Handling of environment variables within single command context
* Robustness against invalid commands, multiple spaces, empty input, and EOF

---

### 📌 Notes and Limitations

* Environment variables do not persist between separate commands since each runs in its own subprocess.
* No job control beyond background execution (`&`).
* Does not currently support scripting or shell expansions beyond what Bash provides in the wrapped commands.

---

### 🚀 Project Overview

This project demonstrates core shell functionalities through a C implementation that leverages Bash for command execution, enabling quick, clean, and extensible shell behavior.

---

### Future

Will be de-wrapped soon!

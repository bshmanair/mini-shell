CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
SRC = src/main.c src/tokenizer.c src/executor.c
OUT = main

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)

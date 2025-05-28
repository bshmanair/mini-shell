#!/bin/bash
set -e

echo "Running smoke test..."

echo "pwd" | ./myshell >/dev/null
echo "echo Hello" | ./myshell | grep -q Hello
echo "ls" | ./myshell >/dev/null
echo "exit" | ./myshell >/dev/null

echo "All basic tests passed ✅"

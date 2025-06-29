#ifndef HELPER_H
#define HELPER_H

void free_tokens(char **tokens);
char *rejoin(char **tokens);
char *substring(const char *src, int start, int length);
char *merge(char *a, char *b);

#endif
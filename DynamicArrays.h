#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *data;
    size_t size;
    size_t capacity;
} DynamicArray;

DynamicArray *createArray(size_t initialCapacity);
void insertElement(DynamicArray *arr, int value);
void deleteArray(DynamicArray *arr);
void printArray(DynamicArray *arr);

#endif

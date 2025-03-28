#include "DynamicArrays.h"

//FUUUUUUUUUUUUUUUUUUUUUUUUUUUUCK
DynamicArray *createArray(size_t initialCapacity)
{
    // create new array and allocate size of dynamic array
    DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
    // data is the array, so allocate initial capacity to it
    arr->data = (int *)malloc(initialCapacity * sizeof(int));
    // initial size of array is 0
    arr->size = 0;
    // initial capacity is inputted by user
    arr->capacity = initialCapacity;
    return arr;
}

void insertElement(DynamicArray *arr, int value)
{
    // if arr size after inserting equals capacity, double it
    if (arr->size + 1 == arr->capacity)
    {
        arr->capacity *= 2;
        arr = (DynamicArray *)realloc(arr, arr->capacity);
    }
}

void minimizeCapacity(DynamicArray *arr)
{
    arr->capacity = arr->size;
    arr = (DynamicArray *)realloc(arr, arr->capacity);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *create_generic_array(size_t element_size, size_t count)
{
    return malloc(element_size * count);
}

void set_element(void *array, size_t index, void *value, size_t element_size)
{
    memcpy(
        (char*)array + (index * element_size),
        value,
        element_size
    );
}

void get_element(void *array, size_t index, void *dest, size_t element_size)
{
    memcpy(
        dest,
        (char*)array + index * element_size,
        element_size
    );
}

int main()
{
    void* hi =
}
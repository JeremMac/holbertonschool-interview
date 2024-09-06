#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sift_down(int *array, size_t size, size_t index)
{
    size_t largest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != index)
    {
        swap(&array[index], &array[largest]);
        print_array(array, size);
        sift_down(array, size, largest);
    }
}

void heap_sort(int *array, size_t size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i);

    for (size_t i = size - 1; i > 0; i--)
    {
        swap(&array[0], &array[i]);
        print_array(array, size);
        sift_down(array, i, 0);
    }
}

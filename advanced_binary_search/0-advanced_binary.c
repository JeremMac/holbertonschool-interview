#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Print the array being searched
 * @array: The array to print
 * @size: The size of the array
 */
void print_array(int *array, size_t size)
{
	size_t i;

	if (size == 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i++)
	{
		if (i < size - 1)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}
}

/**
 * binary_search - Recursive binary search for the first occurrence
 * @array: The array to search
 * @left: The left index of the subarray
 * @right: The right index of the subarray
 * @value: The value to search for
 * Return: The index of the value or -1 if not found
 */
int binary_search(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	if (left > right)
		return (-1);

	printf("Searching in array: ");
	print_array(array + left, right - left + 1);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		if (mid == left || array[mid - 1] < value)
			return (mid);
		return (binary_search(array, left, mid - 1, value));
	}
	else if (array[mid] < value)
		return (binary_search(array, mid + 1, right, value));
	else
		return (binary_search(array, left, mid - 1, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array
 * @array: The array to search
 * @size: The number of elements in the array
 * @value: The value to search for
 * Return: The index of the value or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (binary_search(array, 0, size - 1, value));
}

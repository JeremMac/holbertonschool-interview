#include "sort.h"
#include <stdlib.h>
#include <unistd.h>

/**
 * get_max - Returns the maximum value in an array
 *
 * @array: The array to be checked
 * @size: The size of the array
 * Return: The maximum value
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - A function to perform counting sort based on exp
 *
 * @array: The array to be sorted
 * @size: The size of the array
 * @exp: The exponent to determine the digit to sort by
 */
void counting_sort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};

	/* Count occurrences of each digit */
	for (size_t i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Update count[i] so it contains the position of this digit in output */
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (ssize_t i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy output array to the original array */
	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	/* Print array after sorting by current digit */
	print_array(array, size);

	/* Free dynamically allocated memory */
	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using Radix sort
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	int max = get_max(array, size);

	/* Perform counting sort for each digit, moving left (exp *= 10) */
	for (int exp = 1; max / exp > 0; exp *= 10)
		counting_sort(array, size, exp);
}

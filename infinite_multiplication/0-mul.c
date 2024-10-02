#include "holberton.h"
#include <stdlib.h>

/**
 * _print_error - Prints error and exits with status 98
 */
void _print_error(void)
{
	char *err = "Error\n";
	int i = 0;

	while (err[i])
	{
		_putchar(err[i]);
		i++;
	}
	exit(98);
}

/**
 * _isdigit - Checks if a string contains only digits
 * @s: String to check
 * Return: 1 if the string contains only digits, 0 otherwise
 */
int _isdigit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _strlen - Calculates the length of a string
 * @s: The string to calculate the length of
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;
	return (len);
}

/**
 * _init_result - Initializes a result array to 0
 * @size: Size of the array
 * Return: Pointer to the initialized array
 */
int *_init_result(int size)
{
	int *result = malloc(size * sizeof(int));
	int i;

	if (!result)
		_print_error();

	/* Initialize the result array to 0 */
	for (i = 0; i < size; i++)
		result[i] = 0;

	return (result);
}

/**
 * multiply - Multiplies two numbers represented as strings
 * @num1: First number as a string
 * @num2: Second number as a string
 * Return: Pointer to the result string
 */
char *multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1), len2 = _strlen(num2);
	int *result = _init_result(len1 + len2);
	char *res_str;
	int i, j, /*carry,*/ sum;

	/* Perform multiplication */
	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			sum = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1];
			result[i + j + 1] = sum % 10;
			result[i + j] += sum / 10;
		}
	}

	/* Convert result array to string */
	res_str = malloc(len1 + len2 + 1);
	if (!res_str)
		_print_error();

	for (i = 0, j = 0; i < len1 + len2; i++)
	{
		if (!(j == 0 && result[i] == 0)) /* Skip leading zeros */
			res_str[j++] = result[i] + '0';
	}
	res_str[j] = '\0';

	free(result);
	return ((res_str[0] == '\0') ? "0" : res_str);
}

/**
 * main - Multiplies two positive numbers
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	char *result;

	/* Check for valid number of arguments */
	if (argc != 3)
		_print_error();

	/* Check if both arguments are digits */
	if (!_isdigit(argv[1]) || !_isdigit(argv[2]))
		_print_error();

	/* Multiply the two numbers */
	result = multiply(argv[1], argv[2]);

	/* Print the result */
	for (int i = 0; result[i]; i++)
		_putchar(result[i]);
	_putchar('\n');

	free(result);
	return (0);
}

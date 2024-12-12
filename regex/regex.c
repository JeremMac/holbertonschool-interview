#include "regex.h"

/**
 * regex_match - Checks if the string matches the pattern.
 * @str: The string to scan.
 * @pattern: The regular expression.
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern)
{
	if (*pattern == '\0')
	{
		return (*str == '\0');
	}

	if (*(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
		{
			return (1);
		}
		if ((*str != '\0' && (*str == *pattern || *pattern == '.')) &&
				regex_match(str + 1, pattern))
		{
			return (1);
		}
	}
	else if (*str != '\0' && (*str == *pattern || *pattern == '.'))
	{
		return (regex_match(str + 1, pattern + 1));
	}

	return (0);
}

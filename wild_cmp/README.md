# Wild Compare

## Description

The "Wild Compare" project involves implementing a function that compares two strings and determines if they can be considered identical. The second string may contain the special character `*`, which can replace any string, including an empty string.

## Features

- **wildcmp**: Function that compares two strings:
  - **Prototype**: `int wildcmp(char *s1, char *s2);`
  - **Parameters**:
    - `s1`: The first string to compare.
    - `s2`: The second string, which may contain the `*` character.
  - **Returns**:
    - `1` if the strings are identical.
    - `0` otherwise.

## Compilation

To compile the program, use the following command:

```bash
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp

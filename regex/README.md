regEx

## Description

This project implements a function in C that checks if a given string matches a simple regular expression pattern. The function supports special characters `.` and `*`:
- `.` matches any single character.
- `*` matches zero or more occurrences of the preceding character.

## Features

- Pattern matching with strings.
- Support for special characters for flexible matching.
- Compliance with Betty coding style.

## Prerequisites

- Compile on Ubuntu 14.04 LTS.
- Use `gcc` version 4.8.4 with the following flags:
  - `-Wall`
  - `-Werror`
  - `-Wextra`
  - `-pedantic`

## Files

- `regex.h`: Header file containing the function declaration.
- `regex.c`: Implementation of the `regex_match` function.
- `main.c`: Test file demonstrating the function's functionality.

## Compilation

To compile the project, use the following command:

```bash
gcc -Wall -Wextra -Werror -pedantic main.c regex.c

## Execution
./a.out 
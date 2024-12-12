# Pascal's Triangle

This project contains a Python function that generates Pascal's Triangle for a given integer `n`.

## Functionality

The function `pascal_triangle(n)` returns a list of lists of integers representing Pascal's Triangle of size `n`. If `n` is less than or equal to 0, the function returns an empty list.

### Example Usage

To use the function, you can import it into your script and call it as follows:

```python
from 0-pascal_triangle import pascal_triangle

def print_triangle(triangle):
    """
    Print the triangle
    """
    for row in triangle:
        print("[{}]".format(",".join([str(x) for x in row])))

if __name__ == "__main__":
    print_triangle(pascal_triangle(5))

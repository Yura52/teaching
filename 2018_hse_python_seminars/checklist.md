# Checklist for writing C++ code

## Code style
_Always_ (don't even think of opposite):
- strictly follow this codestyle: https://www.python.org/dev/peps/pep-0008

## Input/Output
_Always_ (don't even think of opposite):
- For printing use f-strings (works only if Python >= 3.6, in older versions use `.format()`). Obviously, if you just need to print `x` or convert `x` to string then `print(x)` and `str(x)` are better options :)

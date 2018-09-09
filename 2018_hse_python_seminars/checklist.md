# Checklist for writing C++ code

## Code style
_Always_ (don't even think of opposite):
- strictly follow this codestyle: https://www.python.org/dev/peps/pep-0008

## Input/Output
When possible (there are very few cases when it's better to prefer opposite):
- For printing use f-strings (works only if Python >= 3.6, in older versions use `.format()`; of course)

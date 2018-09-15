# Checklist for writing C++ code

## Code style
_Always_ (don't even think of opposite):
- strictly follow this codestyle: https://www.python.org/dev/peps/pep-0008

## Input/Output
_Always_ (don't even think of opposite):
- For printing use f-strings (works only if Python >= 3.6, in older versions use `.format()`). Obviously, if you just need to print `x` or convert `x` to string then `print(x)` and `str(x)` are better options :)

## Variables
_Always_ (don't even think of opposite):
- Use variables to remove hardcoded constants from your code. For example, if it is
said that the stream of numbers will end when zero occurs, then the bad way to code
it is `while current_number != 0` and the right way is `while current_number != LAST_NUMBER`.
It's better because if you have to change zero to something different you'll have
to change just one variable instead of all the places where use used `0`.
Moreover, the latter way is more readable, because an external reader will
immediately understand what the variable means whilst in the former way it's
just `0` and it's not clear why zero, why stop when zero etc.

When possible (there are very few cases when it's better to prefer opposite):
- Avoid using global variables. In

## Functions
_Always_ (don't even think of opposite):
- Use functions to: remove duplicating code, improve readibility of your code
- Use typehints in your functions' signatures

## Other
_Always_ (don't even think of opposite):
- When writing scripts, define the `main` function and use `if __name__ == '__main__'` to run it.
It allows to import functions (including `main`) from your script.

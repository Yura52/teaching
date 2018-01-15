# Checklist for writing C++ code

## Code style
http://google.github.io/styleguide/cppguide.html

## Types, variables
_Always_ (don't even think of opposite):
- prefer types from [\<cstdint\>](http://en.cppreference.com/w/cpp/header/cstdint) to `int`, `long` etc.

_When possible_ (there are very few cases when it's better to prefer opposite):
- initialize variables when default value is not determinate
- use `auto`
- use `const`
- prefer simple structs instead of using `std::pair` (it improves readabily: clear field names instead of `first` and `second`)

## Functions

_When possible_ (there are very few cases when it's better to prefer opposite):
- pass input arguments of primitive types by `const` value
- pass input arguments of complex types by `const` reference
- pass output arguments by pointers (raw pointers are suitable for this purpose)

## Memory, pointers
_When possible_ (there are very few cases when it's better to prefer opposite):
- use smart pointers instead of raw pointers (raw pointers are ok for output arguments and can be ok for low-level memory processing)
- use `std::make_unique` and `std::make_shared`

_Remember_
- If there is `delete` in your code and you are not writing library-like low-level code than for 99% you are doing something wrong; consider smart pointers to avoid that

## Iterators
_Always_ (don't even think of opposite):
- use `std::begin`, `std::end` instead of `.begin()`, `.end()`

## Lambdas
_When possible_ (there are very few cases when it's better to prefer opposite):
- use `auto` in lambdas' signatures

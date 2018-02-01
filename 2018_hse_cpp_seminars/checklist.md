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

## Inheritance
_Always_ (don't even think of opposite):
- use "override" keyword when overriding a virtual method
- don't call virtual methods from constructors and destructors
- don't let exceptions leave destructor

_When possible_ (there are very few cases when it's better to prefer opposite):
- when you work with inheritance, write code in terms of pointers to base classes
- if you are going to inherit from a class, ensure that it has a virtual destructor
- prefer free non-friend functions to methods

_Remember_
- virtual functions are not free (perfomance reduction); sometimes alternatives are better (templates)
- model "is-a" relationship via public inheritance
- model "has-a" or "is-implemented-in-terms-of" via composition
- use private inheritance to inherit features of a base class
- Your code usually should give an abstraction, which corresponds to how the real world is designed; however, internal implementation can be absolutely different from that

## Lambdas
_When possible_ (there are very few cases when it's better to prefer opposite):
- use `auto` in lambdas' signatures

# Checklist for writing C++ code

## Code style
http://google.github.io/styleguide/cppguide.html

## Types, variables
_Always_ (don't even think of opposite):
- prefer types from [\<cstdint\>](http://en.cppreference.com/w/cpp/header/cstdint) to `int`, `long` etc.; if you prefer more concise style, you can do `using i32 = int32_t;` and similar staff at the beginning of your programs 

_When possible_ (there are very few cases when it's better to prefer opposite):
- initialize variables of POD (plain old data, i.e. primitive, e.g. `int32_t`, `char` etc.) types
- use `auto`
- use `const`
- prefer simple structs instead of using `std::pair` (it improves readabily: clear field names instead of `first` and `second`)

## `If`-statement
_When possible_ (there are very few cases when it's better to prefer opposite):
- don't omit curly braces (see the codestyle above to learn when it is appropriate to omit them)

## Loops
_Always_ (don't even think of opposite):
- use "range-based for loop" when possible; if it is not possible, iterate via iterators; only iterators don't fit your
needs either, use indexing

## Functions
_When possible_ (there are very few cases when it's better to prefer opposite):
- pass input arguments of primitive types by `const` value (without `const` in declarations; with `const` in definitions)
- pass input arguments of complex types by `const` reference
- pass output arguments by pointers (raw pointers are suitable for this purpose)

## Containers
_Always_ (don't even think of opposite):
- use `reserve` method if you know beforehand how many elements you are going to store in the container

## Memory, pointers
_When possible_ (there are very few cases when it's better to prefer opposite):
- use smart pointers instead of raw pointers (raw pointers are ok for output arguments and can be ok for low-level memory processing)
- use `std::make_unique` and `std::make_shared`

_Remember_
- If there is `delete` in your code and you are not writing library-like low-level code than for 99% you are doing something wrong; consider smart pointers to avoid that

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

## Advanced topics
_Always_ (don't even think of opposite):
- use std::move with rvalue references, but `std::forward` with universal references

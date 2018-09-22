## Mutability is a superimportant concept of Python
There are two kinds of objects: mutable and immutable.  
It's impossible to change an **immutable** object inplace. When you try to modify
an **immutable** object, in fact you get a new object...
```python
>>> a = 999999999
>>> first_id = id(a)
>>> a += 1
>>> second_id = id(a)
>>> first_id == second_id
False
```
... or you get an error:
```python
>>> a = 'abc'
>>> a[1] = 'd'
TypeError: 'str' object does not support item assignment
```
When you try to modify a **mutable** object, it is modified inplace:
```python
>>> a = []
>>> first_id = id(a)
>>> a += [123, True]
>>> second_id = id(a)
>>> first_id == second_id
True
>>> a.append('hello')
>>> third_id = id(a)
>>> first_id == second_id == third_id
True
```
Examples of immmutable types: `bool`, `int`, `str`, `tuple`.  
Examples of mutable types: `list`, `dict`.

## In Python, assignment simply changes the reference
- after `a = b` the reference `a` points to the same object as the reference `b`
- after `a = <expression>` the reference `a` points to the object that is the
result of the `expression`

## Passing arguments to a function is assingment
```python
>>> a = 0
>>> def f(x: int):
...     print(x is a)
>>> f(a)  # in fact, what happens: f(x=a)
True
```
In the case of an immutable argument (let's call it `x`), if we change `x`, the
outer object **is not affected**, because "when you try to modify an **immutable**
object, in fact you get a new object":
```python
>>> a = 0
>>> def f(x):
...     print(x is a)
...     x += 1
...     print(x is a)
>>> f(a)
True
False
>>> a
0
```
In the case of a mutable argument (let's call it `x`), if we change `x`, the
outer object **is affected**, because "when you try to modify a **mutable** object,
it is modified inplace":
```python
>>> a = []
>>> def f(x):
...     print(x is a)
...     x.append(1)
...     print(x is a)
>>> f(a)
True
True
>>> a
[1]
```

## List slice is a **new list** that contains **old references**
```python
>>> a = [[], 1, 'abc']
>>> b = a[:]
>>> a is b
False
>>> a[0] is b[0]
True
>>> a[1] is b[1]
True
>>> a[2] is b[2]
True
>>> b.append(False)
>>> b
[[], 1, 'abc', False]
>>> a
[[], 1, 'abc']  # `a` was not changed, because `a` is not `b`
>>> b[0].append(123)
>>> b
[[123], 1, 'abc', False]
>>> a
[[123], 1, 'abc']  # a[0] was changed, because a[0] is b[0]
```

## Use `copy.deepcopy` (not slice) to prevent modification of nested mutable objects
Compare this...
```python
>>> a = [[]]
>>> b = a[:]
>>> a is b
False
>>> a[0] is b[0]
True
>>> b[0].append(1)
>>> a[0]
[1]
```
... to this:
```python
>>> import copy
>>> a = [[]]
>>> b = copy.deepcopy(a)
>>> a is b
False
>>> a[0] is b[0]
False
>>> b[0].append(1)
>>> a[0]
[]

>>> def f(x):
...     x.append(1)
>>> a = [[]]
>>> f(a)
>>> a
[[1]]
>>> a = [[]]
>>> f(a[:])
>>> a
[[1]]
>>> a = [[]]
>>> f(copy.deepcopy(a))
>>> a
[[]]
```

## Use list comprehensions
They are easier to read and write. So, **do** it like this...
```python
>>> a = [x for x in range(10) if x % 2 == 0]
>>> a
[0, 2, 4, 6, 8]
```
... and **don't do** it like this:
```python
>>> a = []
>>> for x in range(10):
...     if x % 2 == 0:
...         a.append(x)
>>> a
[0, 2, 4, 6, 8]
```

## Never multiply lists by numbers (use list comprehensions instead)
This code works as expected.
```python
>>> a = [[] for _ in range(2)]
>>> a
[[], []]
>>> a[0].append(1)
>>> a
[[1], []]
```
And this code works as WHAT IS GOING ON:
```python
>>> a = [[]] * 2
>>> a
[[], []]
>>> a[0].append(1)
>>> a
[[1], [1]]
```
Whaaaat? Ok, here is the explanation:
```python
>>> a = [[]] * 2
>>> a[0] is a[1]
True
```
So, multipying list means repeating references. It's superdangerous and non-intuitive.
Don't use this feature. It was designed by mistake.

## Default arguments
It's easy:
```python
>>> def f(x=1):
...     return 999
>>> f(0)
0  # as expected
>>> f()
999
```

## Never use mutable objects as default argument values (use `None` instead)
```python
>>> def f(x=[]):
...     x.append(0)
...     return x
>>> a = [1, 2, 3]
>>> f(a)
[1, 2, 3, 0]  # as expected
>>> a
[1, 2, 3, 0]  # as expected
>>> f()
[0]  # as expected
>>> f()
[0, 0]  # whaaaat
>>> f()
[0, 0, 0]  # stop it pls
```
It happens because **the object for the default value is reused every time**, it
is never created from scratch.
The correct way:
```python
>>> def f(x=None):
...     if x is None:
...         x = []
...     x.append(0)
...     return x
```
So, if you want your argument `x` to have the default value `<some_mutable_object>`,
then write:
```python
>>> def f(x=None):
...     if x is None:
...         x = <some_mutable_object>
...     ...
```

## Avoid recursions if possible
In fact, function calls are not free: it takes some time and memory to call a function.
It entails some constraints on the number of nested function calls you can make:
```python
>>> def f(x):
...     if x == 0:
...         return 0
...     else:
...         return f(x - 1)
>>> f(999999999)
RecursionError: maximum recursion depth exceeded in comparison
```
There is a way to check the limit:
```python
>>> import sys
>>> sys.getrecursionlimit()  # The result depends on your computer and system
3000
```
Usually you don't have to worry about that, however, there is one case when you do: recursions.
You have to be very careful and prevent scenarious when a function calls itself
too many times. If it's easy to rewrite such function in terms of loops, then do that: loops
work much faster then function calls and they don't have any constraints :)

## Help
It's a fast way to find documentation. Try this (in order to quit the help, press 'q')
```python
>>> help(print)
```

## Ellipsis
```python
>>> ...
Ellipsis
```
How to use `...` ? I have no idea :)

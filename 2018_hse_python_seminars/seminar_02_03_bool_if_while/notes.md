## bool
Some documentation about `bool` and its applications:
1. https://docs.python.org/3/library/stdtypes.html#truth-value-testing
2. https://docs.python.org/3/library/stdtypes.html#boolean-operations-and-or-not
3. https://docs.python.org/3/library/stdtypes.html#comparisons

Example:
```python
>>> a = 0
>>> b = 1
>>> c = 2
>>> x = b
>>> if x == a:
...    print('aaaaaa')
... elif x == b:
...    print('bbbbbb')
... elif x == c:
...    print('cccccc')
... else:
...    print('HSE')
bbbbbb
```

## Attributes, methods, `dir`
Attributes are objects, related to your object. You can list all the attributes
via the function `dir`:
```python
>>> x = -1
>>> print(dir(x))
['__abs__', '__add__', '__and__', '__bool__', '__ceil__', '__class__', '__delattr__', '__dir__', '__divmod__', '__doc__', '__eq__', '__float__', '__floor__', '__floordiv__', '__format__', '__ge__', '__getattribute__', '__getnewargs__', '__gt__', '__hash__', '__index__', '__init__', '__init_subclass__', '__int__', '__invert__', '__le__', '__lshift__', '__lt__', '__mod__', '__mul__', '__ne__', '__neg__', '__new__', '__or__', '__pos__', '__pow__', '__radd__', '__rand__', '__rdivmod__', '__reduce__', '__reduce_ex__', '__repr__', '__rfloordiv__', '__rlshift__', '__rmod__', '__rmul__', '__ror__', '__round__', '__rpow__', '__rrshift__', '__rshift__', '__rsub__', '__rtruediv__', '__rxor__', '__setattr__', '__sizeof__', '__str__', '__sub__', '__subclasshook__', '__truediv__', '__trunc__', '__xor__', 'bit_length', 'conjugate', 'denominator', 'from_bytes', 'imag', 'numerator', 'real', 'to_bytes']
```
You can access the attributes via a dot: `x.<attribute name>`:
```python
>>> x.__abs__
<method-wrapper '__abs__' of int object at ...>
```
Methods are attributes that can be called:
```python
>>> x.__abs__()
1
```
Have you noticed? Yes, that's exactly what happens when you use the built-in
function `abs`: Python looks for the method `__abs__` and calls it.

## Attributes are building blocks
Let's look at other examples such as `__abs__` from the prevoius section.

#### `bool(x)`
```python
>>> x = -1
>>> bool(x)
True
>>> x.__bool__()
True
```
So, when you `bool(x)` in fact Python firstly looks for the method `__bool__` and
if it is presented, calls it. If not (for example lists do not have the attribue
`__bool__`), then Python looks for the method `__len__` and calls it. This
method is supposed to return the length of the object. If it's zero than
`bool(x)` will be False and otherwise True.

#### `a < b`
```python
>>> a = 1
>>> b = 2
>>> a < b
True
>>> a.__lt__(b)  # less than
True
```
Similar examples:
- `__le__` ~ less or equal ~ <=
- `__eq__` ~ equal ~ ==
- `__ge__` ~ greater or equal ~ >=
- `__gt__` ~ greater than ~ >
- `__ne__` ~ not equal ~ !=

#### a + b
```python
>>> a = 1
>>> b = 2
>>> a + b
3
>>> a.__add__(b)
3
```

#### x()
```python
>>> print('hello', 'world)
hello world
>>> print.__call__('hello', 'world')
hello world
```

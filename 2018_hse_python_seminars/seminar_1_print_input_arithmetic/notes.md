### `print`
Documentation: https://docs.python.org/3/library/functions.html#print
```python
>>> print(1, 2, 3)
1 2 3

>>> print(1, 2, 3, sep='::', end='')
1::2::3
>>> # (no empty line above)
```

### f-strings
For printing use f-strings (works only if Python >= 3.6, in older versions use `.format()`):
Documentation: https://docs.python.org/3/library/string.html#format-string-syntax
```python
>>> a = 2
>>> b = 3
>>> print(f'{a} + {b} = {a + b}')
2 + 3 = 5

>>> apple_count = 14
>>> print(f'I have {apple_count} apples')
I have 14 apples
```

### `id`, `is`
It helps you to check if different variables point to the same object.
Documentation: https://docs.python.org/3/library/functions.html#id
```python
>>> aaa = 2
>>> bbb = abc
>>> id(aaa) == id(bbb)
True
>>> a is b  # it's exactly the same as the check above "id(aaa) == id(bbb)"
True
>>> b is a
True
>>> aaa += 1  # now aaa points to a brand new object (3) and bbb still points to the old one (2)
>>> a is b
False
```

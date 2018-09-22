## Float
The main rule: **DO NOT COMPARE FLOATS**. Reason: float numbers are stored with
non ideal precision:
```python
>>> 0.1 + 0.2 == 0.3
False
>>> 1.0 + 1.0 == 2.0000000000000001
True
>>> 2.0 < 2.0000000000000001
False
```
The solution is some precision that is suitable for your problem,
for example: `eps = 1e-5`. Then you can "compare" floats like this:  
`a == b` ===> `abs(a - b) < eps`  
`a < b` &nbsp;&nbsp;===> `a < b - eps`  
etc.

## Math
A useful library with math routines.  
Documentation: https://docs.python.org/3/library/math.html

## Strings in Python
1. Documentation for `str`: https://docs.python.org/3/library/stdtypes.html#string-methods
2. Documentation for `string`: https://docs.python.org/3/library/string.html
3. In Python, string are immutable.
4. If you want to perform any operation on string, firstly check the methods of
`str` and the module `string`, because the operation is likely to be already implemented there.

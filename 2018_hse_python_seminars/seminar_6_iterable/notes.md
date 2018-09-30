## **Iterable** means "can be used in the `for` loop"
_Examples_: `list`, `tuple`, `str`, `range`, `file`


## There are actions which implicitly use `for`
If you pass something non-iterable to such actions, you'll get an error.

_Example_: `list`, `tuple`
```python
>>> a = list('abc')  # what happens: a = [x for x in 'abc']
>>> a
['a', 'b', 'c']
```
  
_Example_: unpacking. When you write `a, b, c = X`, the right hand side (i.e. `X`) must be iterable.
That's because `a, b, c` is a tuple and the interpreter use the `for` loop to unpack
the right hand side.
```python
>>> a, b = [1, 2]
>>> a, b  # just a reminder: "a, b" is equal to "(a, b)", so it's just a tuple
(1, 2)
>>> a, b = range(2)
>>> a, b
(0, 1)
>>> a, b = open('hello.txt')  # valid if the file contains exactly two lines
>>> a, b = 'c'
ValueError: not enough values to unpack (expected 2, got 1)
>>> a, b = 1, 2, 3
ValueError: too many values to unpack (expected 2)
>>> a, b = 5
TypeError: 'int' object is not iterable
```


## `map(f, iterable)` produces new iterable
The new iterable generates items of the original one, to which `f` was applied.
```python
>>> def f(x):
...     return x * 2
>>> for x in map(f, range(3)):
...     print(x)
0
2
4
>>> list(map(f, (1, 2, 3)))
[2, 4, 6]
>>> list(map(print, [0, 1]))
0
1
[None, None]  # print returns None
>>> map(f, [1, 2, 3])
<map at ...>  # it's not list nor tuple nor anything like that. We will understand that later.
```


## `filter(f, iterable)` produces new iterable
The new iterable generates only such items `x` from the original one that
`bool(f(x)) is True` 
```python
>>> def f(x):
...     return True
>>> list(filter(f, [1, 2, 3]))
[1, 2, 3]
>>> def f(x):
...     return False
>>> list(filter(f, [1, 2, 3]))
[]
>>> def f(x):
...     return x % 2 == 0
>>> def g(x):
...     return x * 3
>>> # in the next example:
>>> # list iterates over map
>>> # map  iterates over filter 
>>> # filter iterates over range (filter generates only even elements from range)
>>> list(map(g, filter(f, range(4))))
[3, 9]
>>> filter(f, [1, 2, 3])
<filter at ...>  # it's not list nor tuple nor anything like that. We will understand that later.
```

## `zip(iterable_1, iterable_2, ...)` produces new iterable
The new iterable generates tuples:
- the **first** tuple contains the **first** elements from the original iterables
- the **second** tuple contains the **second** elements from the original iterables
- the **third** tuple contains the **third** elements from the original iterables
- etc.
- it stops when the smallest iterable is over
```python
>>> def f(x):
...     return x * 2
>>> list(zip([1, 2, 3], map(f, range(10, 20)), 'abc'))
[(1, 20, 'a'), (2, 22, 'b'), (3, 24, 'c')]
>>> for x, y in zip(range(2), 'ab'):  # every tuple from zip is unpacked to `x, y`
...     print(x, y)
0 'a'
1 'b'
```


## It's crucial to know what kinds of iterables exist
**1. Collections**  
All the elements of such iterables already exist and are stored in memory. You can iterate over
them as many times as you want and usually you can iterate over them in the
reversed order via `reversed`  
_Examples_: `list`, `tuple`, `str`

**2. "Generators"**  
None of the elements of such iterables exist beforehand. Instead, they are generated on the fly.  
(_Disclaimer: it Python, the word "generator" means something different, that's
why I put it in quotes. So, in this article I use this word in a different sence.
Please, don't mix it up with its original sence_)
- **2.1**  
You can iterate over them as many times as you want.  
_Examples_: `range`
- **2.2 (A VERY IMPORTANT KIND OF ITERABLES)**  
You can iterate over them only once. After that such iterables are empty.  
_Examples_: file, `map`, `filter`, `zip`, `reversed`, `enumerate`  
This kind of iterables is fundamental and ubiquitous, because usually you don't
need to materialize all the objects at once, you just need to iterate over them.
For example, if you have an immense list with numbers and you want to iterate once only
over even elements, obviously, you don't want to create a new immense list for that.
Instead, you can use `filter` that generates such elements on the fly. Moreover,
when you write `[x for x in immense_list]` a new list is created, so it takes some
time and memory. By contrast, `filter(f, immense_list)` is executed almost instantly, because...
it just doesn't do anything, it simply gets ready for generating elements.
```python
>>> def f(x):
...     return x * 2
>>> m = map(f, range(4))
>>> list(m)
[0, 2, 4, 6]
>>> list(m)
[]  # because the `for` loop was already applied to `m`
>>> def f(x):
...     return x * 2
>>> def g(x):
...     return x % 3 == 0
>>> a = [x for x in range(10000000)]
>>> b = [f(x) for x in a if g(x)]  # takes much time, creates a new big list
>>> c = map(f, filter(g, a))  # takes little time, doesn't create anything
>>> b == list(c)
True
>>> b == list(c)
False  # because we have already applied `for` to `c` and after that `list(c) == []`
```


## Use generator comprehensions
Use them to avoid complex chains of maps, filters, etc.
They are like list comprehensions, but:
- you need to use `()` instead of `[]`
- they don't create any objects (so they don't spend any time and memory)...
- ... so they can be used in the `for` loop only once, after that they are empty
```python
>>> a = (x * 2 for x in range(4) if x % 2 == 0)
>>> type(a)
generator
>>> list(a)
[0, 4]
>>> list(a)
[]  # because `for` has already been applied to `a`
```


## There are useful functions that accept iterables
- `any` returns True if at least one element from an iterable will be True after `bool` is applied. Otherwise, returns False.
- `all` returns True if all the elements from an iterable will be True after `bool` is applied. Otherwise, returns False.
- `sum`, `max`, `min`, etc.


## `itertools` is a library that offers many useful generators
For example, if you want to iterate over a slice of your list, you can use
`itertools.islice`. If you want to simply repeat the same element several times
(or infinitely), use `itertools.repeat`.
```python
>>> import itertools
>>> c = itertools.combinations([1, 2, 3, 4], 3)
>>> list(c)
[(1, 2, 3), (1, 2, 4), (1, 3, 4), (2, 3, 4)]
>>> list(c)
[]
```


## Learn `next`, `iter` and how `for` works under the hood
- How to extract the first element from a generator (`map`, `filter` etc.)?
- What exactly happens when you write `for`?
- How to create your own iterables?

Let's try to answer all these questions.
When you write `for`, firstly, an **iterator** (a special object for iterating) is created via `iter`.
If your iterable is a collection, than this iterator is a different object.  
If your iterable is a "generator", than *usually* the object itself is returned.
```python
>>> a = [1, 2]
>>> iter_a = iter(a)
>>> a is iter_a
False
>>> def f(x):
...     return x * 2
>>> m = map(f, a)
>>> iter_m = iter(m)
>>> m is iter_m
True
>>> iter(iter_a) is iter_a
True
```

After that, at the beginning of every iteration, `next` is applied to the iterator.
When `next` is applied and iterator still has some elements, the next element is returned.
Otherwise, the loop stops.
```python
>>> # it's a continuation of the previous section with code
>>> next(iter_a)
1
>>> next(iter_a)
2
>>> next(iter_a)
Error: StopIteration
>>> next(iter_m)
2
>>> next(iter_m)
4
>>> next(iter_m)
Error: StopIteration
```

Now you can understand why you can iterate over generators only once: because
they are iterators for themselves. And since you can iterate over an iterator only once
(regardless of what the iterator belongs to: collection or generator), you can iterate
over generator only once, too.

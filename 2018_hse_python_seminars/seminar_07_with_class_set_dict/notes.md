## Use `with` to minimize human factor
Firstly, the syntax (the motivation for usage is given at the end of this section).
Before:
```python
>>> a = <some expression>
>>> do_the_job(a)
```
After:
```python
>>> with <some expression> as a:
...     do_the_job(a)
```
It works only if the result of `<some expression>` has the methods `__enter__` and `__exit__`:
```python
>>> with open('path/to/some/file') as f:  # ok
...     pass
>>> with 5 as a:  # not ok, int doesn't have the methods `__enter__` and `__exit__`
...     pass
AttributeError: __enter__
```

_Motivation_: You should use `with` and should support `with` for your own classes
if there are some necessary actions that should be done after `do_the_job`.

_Example_: all opened files must be closed. It's extremely error-prone to write `f.close()` by hands because
it is super easy to forget to do it. So, the whole point is in making such actions happen
automatically. So, when you write `with open(...) as f:` the file will always be closed
because the method `__exit__` is always called (at the end of the `with` block) and
inside this method file is closed (it was a long sentence, so probably you should read it
again).

_Example_: if you write the class `DBConnection` (Database Connection), you probably should
write the method `__enter__` which does nothing and the method `__exit__` where connection
is closed, so that users can write:
```python
>>> with DBConnection(some_parameters) as connection:
...     do_the_job(connection)
```
instead of
```python
>>> connection = DBConnection(some_parameters)
>>> do_the_job(connection)
>>> connection.close()
```


## Distinguish between "class" and "object of the class"
```python
>>> a = int()
>>> a
0
```
In the example: `int` is a **class**, `a` is an **object of the class `int`**.


## Learn how to create classes
_Example_: let's start with the simplest class in the world
```python
>>> class File:
...     pass
>>> f = File()
```

_Example_: let's add a method which says "hello". All methods must accept at least one argument. This argument should be called `self`. It's the object, the method of which is called.
```python
>>> class File:
...     def hello(self):
...         print('hello')
>>> f = File()
>>> f.hello()
hello
```

_Example_: let's prove the point about `self`:
```python
>>> class File:
...     def get_id(self):
...         return id(self)
>>> f = File()
>>> id(f) == f.get_id()
True  # we've just proven that `f` and `self` is the same object
```

_Example_: Let's support `with`. In the `__enter__` method we shouldn't do anything
special, however, it the `__exit__` we should close the file (for that we will also
add the method `close`).
```python
>>> class File:
...     def close(self):
...         print('I am closed!')
... 
...     def __enter__(self):
...         print('__enter__')
... 
...     def __exit__(self):
...         print('__exit__')
...         self.close()
>>> with File() as f:
...     pass
__enter__
__exit__
I am closed!
```


## Read the documentation for `dict` and `set`
Both classes are packed with numerous useful methods. That's why you should always
consult the documentation before writing any code for `dict` or `set`, because what you
may want to write is likely to be already implemented.  
`dict`: https://docs.python.org/3/library/stdtypes.html#mapping-types-dict  
`set`: https://docs.python.org/3/library/stdtypes.html#set  


## Operator `in` checks if a value is in some collection or iterable
```python
>>> 1 in [1, 2, 3]
True
>>> 4 in [1, 2, 3]
False
```


## `in` works for **O(n)** for `list` and for **O(1)** for `set`/`dict`...
Let's show it (I use some nonstandard console `ipython` for that; actually, I
recommend to use it, because it's very convenient):
```python
>>> size = 10000000
>>> a = list(range(size))
>>> %%time
... size in a
Wall time: 120 ms
False
>>> b = set(a)
>>> %%time
... size in b
Wall time: 6.2 µs
False
```
The `set` was 20000x faster! The reason is the way `list` and `set` are implemented.  
- When you search in `list`, you simply try all the elements one by one from the beginning
to the end, because `list` is just an array of references. When you append new objects to `list`,
they are simply inserted in the end.  
- `set` is implemented in a completely different way. Inside there is a special data structure
called **hash table**. For now, you can think that it's an array of references, too,
but the position (i.e. index) for every element can be calculated. When you insert a new element,
this position is calculated and the element is inserted in that position. So, when you
search for the element, two steps are done: 1) calculate the position 2) check if there is our value in that position.
Obviusly, it's much faster than trying all the elements one by one.


## ... but it doesn't mean that you should always use `set`
_Remember_: `list` is a very simple data structure, and for simple operation it performs
faster (such as inserting a new element). Also, using `list`, you can control the order how
the elements are stored (for example, if it's important to remember the order in which
the elements are inserted or you want to keep elements in a sorted order), you also
can access elements by index.
By contrast, when you iterate over `set`, you get elements in a "random" order (i.e. you cannot control it).

_Example_: if you have a `list` and want to search for some value just once, don't convert
it to `set`, because creating a `set` also takes time. Remember: searching in a `list`
is one simple loop, but creating a set is a loop over the same list (and the loop
is not that simple, actually). Let's measure time taking creating `set` into account:
```python
>>> size = 10000000
>>> a = list(range(size))
>>> %%time
... size in a
Wall time: 120 ms
False
>>> %%time
... b = set(a)
... size in b
Wall time: 434 ms
False
```
Now it's 3.5x slower.

_Example_: if `a` and `b` are both lists of **unique** elements, how would you find
the number of common elements?
- _bad solution_: `len(set(a) & set(b))`
- _good solution_: `set_a = set(a); sum(1 for x in b if x in set_a)`  
Explanation: in fact, the question is "how many elements of `b` are stored in `a`?"
(of course, it's the same as "how many elements of `a` are stored in `b`?"). We know,
that many searches can be done more efficiently if we search in `set`, that's why
one of the lists should be converted to `set`. Secondly, we have to iterate **once**
over another list and search for every element in the created `set`. And it is absolutely
useless to convert the second `list` to `set` for that, because you can just iterate over the original `list`.
```python
>>> size = 10000000
>>> a = list(range(size))
>>> b = list(range(size))
>>> %%time
... len(set(a) & set(b))
Wall time: 1.51 s
10000000
>>> %%time
... set_a = set(a)
... sum(1 for x in b if x in set_a)
Wall time: 1.35 s
10000000
```
As a bonus, one more bad solution. We can sum bools, right?
```python
>>> %%time
... sum(x in set_a for x in b)
Wall time: 1.57 s
10000000
```
Don't do that. It's slower because of conversions.


## Use `frozenset` if you don't plan to mutate your set
It's just faster. You can think of it as about "`list` vs `tuple`": `tuple` is faster
and more compact than `list`, but doesn't allow to mutate it.
The same applies to "`frozenset` vs `set`". So, the ideal solution of the
previous example uses `frozenet` instead of `set`.

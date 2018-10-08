## Learn how to work with files
- use `with` when opening files
- use `readline` to read a signle line
- use `read` to read the whole content
- use the `for` loop to iterate over lines

Documentation: https://docs.python.org/3/tutorial/inputoutput.html#methods-of-file-objects


## Use `itertools.chain` to iterate over items of several iterables
Just pass them as several arguments to the constructor
```python
>>> import itertools
>>> list(itertools.chain(['a', 'b'], range(3)))
['a', 'b', 0, 1, 2]
```
Alternatively, if you have an iterable, that contains iterables, use
`itertools.chain.from_iterable`
```python
>>> d = {'Peter': ['A', 'B'], 'Ivan': ['C', 'D']}
>>> # just a reminder: `d.values()` returns an iterator over values
>>> # in our example, this iterator will produce two elements: `['A', 'B']` and `['C', 'D']`
>>> # however, the goal is to iterate over `A`, `B`, `C`, `D`, not over lists.
>>> list(itertools.chain.from_iterable(d.values()))
['A', 'B', 'C', 'D']  # success!
```


## Learn `collections`
This standard module contains several useful classes.  
Documentation: https://docs.python.org/3/library/collections.html

#### `defaultdict`  
It should be used when you want automatically insert a default value in dict
for a missing key without preliminary checks. The default value is made via a
factory callable that must be passed to the constructor: `defaultdict(factory)`.  
The factory must allow to make a call WITHOUT arguments (i.e. just `factory()`).

_Example_:
```python
>>> d = {}  # ordinary dict
>>> d['hello']
KeyError: 'hello'
>>> d
{}
>>> import collections
>>> dd = collections.defaultdict(lambda: 123)  # `lambda: 123` is a factory, that returns 123
>>> dd['hello']
123
>>> dd
{'hello': 123}
>>> # what happened:
>>> # key 'hello' was missing ==> factory was called ==> it returned `123` ==>
>>> # ==> this `123` was inserted with the key `hello`
>>> dd['abc'] += 111
>>> dd
{'hello': 123, 'abc': 234}
>>> # again: `abc` was missing ==> `123` was inserted automatically ==>
>>> # ==> after that `+= 111` was applied
```

_Example_: `defaultdict(int)` or `defaultdict(float)`
can be used if your goal is to collect some scores for every key.
```python
>>> names_and_scores = [
...     ('Sasha', 1),
...     ('Pasha', 2),
...     ('Sasha', 3),
...     ('Pasha', 4)
]
>>> dd = collections.defaultdict(int)  # `int` is a factory, which returns `0` when called
>>> for name, score in names_and_scores:
...     # if `name` is not in `dd`, then the value `int()` (i.e. `0`) is inserted automatically,
...     # because `int` is the factory for `dd`
...     dd[name] += score
>>> dd  #  {'Sasha': 1 + 3, 'Pasha': 2 + 4}
{'Sasha': 4, 'Pasha': 6}
>>> # let's see how it would look for an ordinary dict (spoiler: it looks worse)
>>> d = {}
>>> for name, score in names_and_scores:
...     if name not in d:
...         d[name] = 0
...     d[name] += score
```

_Example_: `defaultdict(list)` can be used if your goal is to collect a list of
items for every key.
```python
>>> names_and_items = [
...     ('Sasha', 'apple'),
...     ('Pasha', 'orange'),
...     ('Sasha', 'banana'),
...     ('Pasha', 'tomato')
]
>>> dd = collections.defaultdict(list)  # `list` is a factory, which returns `[]` when called
>>> for name, item in names_and_items:
...     # if `name` is not in `dd`, then the value `list()` (i.e. `[]`) is inserted automatically,
...     # because `list` is the factory for `dd`
...     dd[name].append(item)
>>> dd
{'Sasha': ['apple', 'banana'], 'Pasha': ['orange', 'tomato']}
>>> # let's see how it would look for an ordinary dict (spoiler: it looks worse)
>>> d = {}
>>> for name, item in names_and_items:
...     if name not in d:
...         d[name] = []
...     d[name].append(item)
```


#### `Counter`
It's a special dict which is especically convenient for storing... counts :) Just
pass an iterable to the constructor and it will count items automatically.
```python
>>> import collections
>>> c = collections.Counter(['a', 'a', 'b', 'b', 'b', 'c'])
>>> c
Counter({'a': 2, 'b': 3, 'c': 1})
>>> c['b']
3
>>> c.most_common(2)  # returns top-2 values and their counts
[('b', 3), ('a', 2)]
>>> c['some_missing_key']  # `0` is not inserted after this!
0
>>> c
Counter({'a': 2, 'b': 3, 'c': 1})  # the key `some_missing_key` is still missing
>>> c + c
Counter({'a': 4, 'b': 6, 'c': 2})
```


#### `namedtuple`
It's like a tuple, but you can give names to the fields and access them by these
names. It can make your code more readable.  
Notice, that **`namedtuple` is used to create classes, not objects**.
```python
>>> Point = collections.namedtuple('Point', ['x', 'y'])  # a new class `Point` is created
>>> p = Point(11, y=22)  # we can omit the names or write them or both
>>> p[0] + p[1]
33
>>> x, y = p
>>> x, y
(11, 22)
>>> p.x + p.y
33
>>> p
Point(x=11, y=22)
```


#### `OrderedDict`
An ordinary `dict` is a hashtable. It means that when you iterate over its keys,
THE ORDER OF KEYS IS UNKNOWN. By contrast, `OrderedDict` remembers the order
in which the keys were inserted (of course, it's not for free, `OrderedDict` works
slower).
```python
>>> d = {}
>>> d[1] = 'b'
>>> d['a'] = 2
>>> for x in d:
...     print(x, end=' ')
<here it may be both `1 a` and `a 1`>
>>> od = collections.OrderedDict()
>>> od[1] = 'b'
>>> od['a'] = 2
>>> for x in od:
...     print(x, end=' ')
1 a  # always in this order, because the key `1` was inserted earlier
```

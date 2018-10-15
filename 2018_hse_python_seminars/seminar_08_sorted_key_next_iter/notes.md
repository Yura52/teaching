## Prefer iterating over items to iterating over indices
Indexing is a source of numerous mistakes leading to `IndexError`. That's because
it's up to you to calculate indices correctly and it's not an easy task to make
indices valid and not to go out of bounds. By contrast, if you iterate over items,
you cannot fail and go out of bounds: instead, you just leave the loop automatically. That's why all modern
languages (and some old ones, too) support iterating over items of a collection. So, it's
better to write
```python
>>> # GOOD
>>> for x in my_list:
...     do_the_job(x)
```
instead of
```python
>>> # BAD
>>> for i range(len(x)):
...     do_the_job(my_list[i]) 
```
Use generators, `next`, `iter`, `itertools` and other tools to avoid indexing.  
However, if you really need indices, use `enumerate`. It enables you to use indices,
while still extracting values for you in a safe manner:
```python
>>> for index, value in enumerate(my_list):
...     do_the_job(index, value)
```


## Use the `key` argument for nontrivial sorting
_Example_: if you have a list of numbers, how to sort indices according to corresponding
values? Such problems are solved in two steps:
- **what do we want to sort**? The indices, i.e. the items are `0, 1, ..., len(my_list) - 1`.  
In other words, we want to sort `range(len(my_list))`
- **how two items are compared**? Index `i` is "less" than index `j` iff `my_list[i] < my_list[j]`

Now, it's easy to write the solution:
```python
>>> sorted(range(len(my_list)), key=lambda x: my_list[x])
```

_Example_: if you have a list of tuples (Name: str, score: int), how to print
all the names in a correspondence with the ascending order of scores. Again, two steps:
- **what do we want to sort**? The names, i.e. `(x[0] for x in my_list)`. However,
we cannot design such `key` that would return score for a given name. So, in fact,
**we have to choose such items, for which we can design a key**. Here we can take
the tuples as they are.
- **how two items are compared**? Tuple A is less than tuple B iff `A[1] < B[1]` (because
the index "1" corresponds to score).
```python
>>> sorted(my_list, key=lambda x: x[1])
```


## Use the `reverse` argument for sorting in the decending order
_Example_: the problem is the same as the previous one, but the desired sort order
is changed.  
A bad, nonreadable solution:
```python
>>> sorted(my_list, key=lambda x: -x[1])
```
A good and clear solution:
```python
>>> sorted(my_list, key=lambda x: x[1], reverse=True)
```
The second solution should be preferred to the first one, because:
- if we want to set the order as the problem's parameter "reverse", then we can write it
as `sorted(my_list, key=lambda x: -[1], reverse=reverse)`. Compare it to
`sorted(my_list, key=lambda x: -x[1] if reverse else x[1])`
- the first solution changes the natural sence of the word "score". It's easier to understand
when we compare scores, but not "scores multiplied by -1".

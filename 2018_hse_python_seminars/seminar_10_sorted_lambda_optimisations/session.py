# coding: utf-8
set().update(range(5))
a = set()
a.update(range(5))
a
get_ipython().run_cell_magic('timeit', '', 'a = set()\na |= set(range(10000))')
get_ipython().run_cell_magic('timeit', '', 'a = set()\na.update(range(10000))')
help(range)
get_ipython().run_line_magic('clear', '')
a
a.remove(range(10)

)
def f(): return x
def f(): return 1
f()
def f(a, b): return a + b
f(1, 2)
clea
get_ipython().run_line_magic('clear', '')
def f(a, b): return a + b
lambda a, b: a + b
g = lambda a, b: a + b
g(1, 2)
'a b 1 2 3'.rsplit(3)
'a b 1 2 3'.rsplit(maxsplit=3)
from itertools import takewhile
list(takewhile(lambda x: x == 1, [1, 1, 2]))
get_ipython().run_line_magic('clear', '')
d = {randint(0, s): {randint(0, s): randint(0, s) for _ in range(10)} for _ in range(s)}
s = 1000000
get_ipython().run_line_magic('clear', '')
s = 100000
d = {randint(0, s): {randint(0, s): randint(0, s) for _ in range(10)} for _ in range(s)}
from random import randint
from random import randint
d = {randint(0, s): {randint(0, s): randint(0, s) for _ in range(10)} for _ in range(s)}
next(iter(d))
d[61186]
get_ipython().run_line_magic('clear', '')
get_ipython().run_cell_magic('time', '', '_ = sorted(d)')
get_ipython().run_cell_magic('time', '', '_ = sorted(d.items())')
get_ipython().run_cell_magic('time', '', '_ = sorted(d.items(), key=lambda x: x[0])')
get_ipython().run_cell_magic('time', '', '_ = sorted(d.items(), key=lambda x: x[0])')
get_ipython().run_line_magic('clear', '')
get_ipython().run_cell_magic('timeit', '', '_ = sorted(d)')
get_ipython().run_cell_magic('timeit', '', '_ = sorted(d.items())')
get_ipython().run_cell_magic('timeit', '', '_ = sorted(d.items(), key=lambda x: x[0])')
get_ipython().run_line_magic('clear', '')
print(*(1 for _ in range(10))
)
0 ^ 1
get_ipython().run_line_magic('clear', '')
get_ipython().run_line_magic('clear', '')
get_ipython().run_line_magic('clear', '')
def f(a, b): return a + b
f(1, 2)
lambda a, b: a + b
g = lambda a, b: a + b
g(1, 2)
get_ipython().run_line_magic('clear', '')
print(len(set(sys.stdin.readline().split()) & set(sys.stdin.readline().split())))
import sys
print(len(set(sys.stdin.readline().split()) & set(sys.stdin.readline().split())))
get_ipython().run_line_magic('clear', '')
get_ipython().run_cell_magic('timeit', '', 'a = set()\na.update(range(1000000))')
get_ipython().run_cell_magic('timeit', '', 'a = set()\na.update(x for x in range(1000000))\n')
a = range(10)
b = (x for x in range(10))
len(a)
len(b)
get_ipython().run_cell_magic('timeit', '', 'a = set()\na.update(range(10000000))\n')
get_ipython().run_cell_magic('timeit', '', 'a = set()\na.update(x for x in range(10000000))\n')
from random import randint
s = 100000
d = {
    randint(0, s): {
        randint(0, s): randint(0, s)
        for _ in range(10)
    }
    for _ in range(s)
}
next(iter(d))
d[32250]
get_ipython().run_line_magic('clear', '')
dd = {'1': {1: 1}, '2': {2: 2}, '3': {3, 3}}
dd
dd = {'1': {1: 1}, '2': {2: 2}, '3': {3: 3}}
keys = sort(dd)
get_ipython().run_line_magic('clear', '')
dd = {1: {1: 1}, 2: {2: 2}, 3: {3: 3}}
sorted(dd)
[x for x in dd]
sorted_keys = sorted(dd)
for x in sorted_keys:
    print(dd[x])
    
claer
get_ipython().run_line_magic('clear', '')
len(d)
get_ipython().run_cell_magic('timeit', '', 'for name in d:\n    for item in d[name]:\n        _ = d[name][item]')
get_ipython().run_cell_magic('timeit', '', 'for name in d:\n    d_name = d[name]\n    for item in d[name]:\n        _ = d_name[item]')
a = []
for x in range(123):
    a.append(x)
    
a_append = a.append
for x in range(123):
    a_append(x)
    
a = [None for _ in range(123)]
for i, x in enumerate(range(123)):
    a[i] = x
    
for x in enumerate(['a', 'b', 'c']):
    print(x)
    
c;ear
get_ipython().run_line_magic('clear', '')
v = ['a', 'b', 'c']
dict(map(reversed, enumerate(v)))
{i: value for i, value in enumerate(v)}
{i: value for i, value, i in enumerate(v)}
get_ipython().run_line_magic('clear', '')
a = 1
b = 2
print(a, b)
c = (a, b)
print(*c)
c = [a, b]
print(*c)
get_ipython().run_line_magic('clear', '')
print(*map(lambda x: x * 2, range(5)))
import itertools
a = [[0, 1], [2, 3]]
for x in a:
    print(x)
    
for x in itertools.chain.from_iterable(a):
    print(x)
    
print(*itertools.chain.from_iterable(a))
get_ipython().run_line_magic('save', 'sess ~0/')

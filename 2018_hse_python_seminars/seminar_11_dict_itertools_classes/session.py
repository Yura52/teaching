# coding: utf-8
a = [[0, 1], [2, 3]]
b = [[1, 2], [3, 4]]
a @ b
class AL
class A:
    @classmethod
    def m(x):
        print(x, type(x))
        
A.m()
A().m()
cler
get_ipython().run_line_magic('clear', '')
'123' * 0 + ' '
import sys
type(sys.stdin)
import _io
from itertools import chin
from itertools import chain
get_ipython().run_line_magic('pinfo', 'chain.from_iterable')
clera
get_ipython().run_line_magic('clear', '')
from random import randint
s = 100000
d = {
    randint(0, s): {
        randint(0, s): randint(0, s)
        for _ in range(10)
    }
    for _ in range(s)
}
k = sorted(d)
items = sorted(d.items())
items[0]
for _, item_count in items:
    pass
get_ipython().run_line_magic('clear', '')
get_ipython().run_cell_magic('timeit', '', '_ = sorted(d)')
get_ipython().run_cell_magic('timeit', '', '_ = sorted(d.items())')
get_ipython().run_cell_magic('timeit', '', '_ = sorted(d.items(), key=lambda x: x[0])')
get_ipython().run_line_magic('clear', '')
is_prime = lambda x: all(x % y != 0 for y in range(1, x))
is_prime(37)
is_prime = lambda x: all(x % y != 0 for y in range(2, x))
is_prime(37)
get_ipython().run_line_magic('clear', '')
def f(x):
    if type(x) == int:
        print('int')
    else:
        print('not int')
        
f(1)
f('a')
def f(x):
    if type(x) is int:
        print('int')
    else:
        print('not int')
        
f('a')
f(1)
get_ipython().run_line_magic('clear', '')
def f(x):
    if type(x) is int:
        print('int')
    else:
        print('not int')
        
def g(x):
    if isinstance(x, int):
        print('int')
    else:
        print('not int')
        
get_ipython().run_line_magic('clear', '')
class A:
    def m(self):
        print('hello')
        
a = A()
a.m()
data = [[0, 1], [2, 3]]
a = [[]]
b = a
b[0].append(1)
a
import copy
get_ipython().run_line_magic('clear', '')
import copy
a = 'abc'
a.upper()
str.upper(a)
a = ['a', 'b', 'c']
[x for x in map(str.upper, a)]
class A:
    def __init__(self, x: int):
        self.x = x
        
class A:
    def __init__(self, x: int):
        self.x = x
    @classmethod
    def from_str(cls, x: str):
        return A(int(x))
    
a = A(5)
b = A.from_str('1')
a.x
b.x
from itertools import chain
a = [1, 2]
b = ['a', 'b']
list(chain(a, b))
list(chain.from_iterable([a, b]))
class Calculator:
    @staticmethod
    def sum(a, b):
        return a + b
    
Calculator.sum(1, 2)
c = Calculator()
c.sum(1, 2)
class A:
    def __init__(self, x):
        self.x = x
        
a = A(5)
a.x
class M:
    def __init__(self, data):
        self.data = copy.deepcopy(data)
        
m = M(data)
data
m[0][1]
class M:
    def __init__(self, data):
        self.data = copy.deepcopy(data)
    def __getitem__(self, index):
        return self.data[index]
    
m = M(data)
m[0][1]
get_ipython().run_line_magic('save', '~0 sessss')
get_ipython().run_line_magic('save', 'sessss ~0')
get_ipython().run_line_magic('save', 'sessss ~0/')

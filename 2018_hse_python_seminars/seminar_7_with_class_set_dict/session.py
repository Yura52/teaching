# coding: utf-8
get_ipython().run_line_magic('clear', '')
a = ['abc', 'def']
'HELLO'.join(a)
'___'.join(a)
a = ['abc', 'def', 'asd']
'___'.join(a)
a = range(10)
'___'.join(a)
'___'.join(map(str, a))
'___'.join([str(x) for x in a])
'___'.join((str(x) for x in a))
b = (str(x) for x in a)
b
list(b)
list(b)
list(b)
b
'___'.join(str(x) for x in a)
a = list(range(10))
a
' '.join(reversed(a))
' '.join(map(str, reversed(a)))
reversed(a)
get_ipython().run_line_magic('clear', '')
a = list(range(10))
[b for x in reversed(a)]
a = list(range(10))
get_ipython().run_line_magic('clear', '')
a = list(range(10))
[x for x in reversed(a)]
b = map(str, a)
[x for x in reversed(b)]
a
a.reverse()
a
get_ipython().run_line_magic('clear', '')
f = open('a.txt')
f = open('a.txt', 'w')
get_ipython().run_line_magic('pinfo', 'print')
print('hello', file=f)
f.write('hello')
f.close()
get_ipython().run_line_magic('cat', 'a.txt')
f = open('b.txt', 'w')
f.write('hello')
f.write('hello')
f.close()
get_ipython().run_line_magic('cat', 'b.txt')
with open('c.txt', 'w') as f:
    f.write('hello\n')
    
with 5 as a:
    print(a)
    
type(f)
get_ipython().run_line_magic('clear', '')
a = list(range(10))
5 in a
dir(a)
a.__contains__(5)
get_ipython().run_line_magic('clear', '')
f
'__enter__' in dir(f)
'__exit__' in dir(f)
help(f.__enter__)
get_ipython().run_line_magic('pinfo', 'f.__enter__')
f.__enter__()
get_ipython().run_line_magic('clear', '')
f = open('a.txt')
f.__enter__()
f.close()
f.close()
f.close()
f.closed
get_ipython().run_line_magic('clear', '')
f = open('a.txt')
f.__exit__()
f.closed
class Student:
    def __enter__(self):
        print('__enter__')
    
class Student:
    def __enter__(self):
        print('__enter__')
    
class Student:
    def __enter__(self):
        print('__enter__')
    def __exit__(self):
        print('__exit__')
        
s = Student()
i = int()
class Student:
    def __enter__(self):
        print('__enter__', id(self))
    def __exit__(self):
        print('__exit__', id(self))
        
        
s = Student()
id(s)
s.__enter__()
class Student:
    def __enter__(self):
        print('__enter__', id(self))
    def __exit__(self):
        print('__exit__', id(self))
        
        
s.__enter__()
id(s)
s.__exit__()
id(s)
Student.__enter__()
def f(x):
    pass
f()
def f():
    pass
f(1)
class Student:
    def __enter__():
        print('__enter__', id(self))
    def __exit__(self):
        print('__exit__', id(self))
        
        
s = Student()
s.__enter__()
a = Student()
b = Student()
a is b
c = 1
d = 1
c is d
c = 9999213139219312
d = 9999213139219312
c is d
class Student:
    def __enter__(self):
        print('__enter__', id(self))
    def __exit__(self):
        print('__exit__', id(self))
        
        
Student().__enter__()
Student().__enter__()
with Student():
    pass
class Student:
    def __enter__(self):
        print('__enter__', id(self))
    def __exit__(self, a, b, c):
        print('__exit__', id(self))
        
        
with Student():
    pass
a
get_ipython().run_line_magic('clear', '')
a = list(range(10))
a[2]
dir(a)
a.__getattribute__(2)
a.__getitem__(2)
a
class Student:
    def __enter__(self):
        print('__enter__', id(self))
    def __exit__(self, a, b, c):
        print('__exit__', id(self))
    def __getitem__(self, food):
        print('omnomnom')
        
        
sirozha = Student()
sirozha['banana']
sirozha.__getitem__('banana')
sirozha['banana']
sirozha['banana']
sirozha['banana']
sirozha['banana']
sirozha['banana']
sirozha['banana']
class Student:
    def __enter__(self):
        print('__enter__', id(self))
    def __exit__(self, a, b, c):
        print('__exit__', id(self))
    def __getitem__(self, food):
        print('omnomnom')
        
        
get_ipython().run_line_magic('clear', '')
max(1, 2)
max(1, 2, 3)
max(1, 2, 3, 4)
def f(*args):
    print(type(args))
    
f()
f(1)
def f(*args):
    print(args, type(args))
    
    
f()
f(1)
f(1, 2)
def g(*args):
    print(args)
    
def f(*args):
    g(args)
    
f(1, 2, 3)
def f(*args):
    g(*args)
    
    
f(1, 2, 3)
get_ipython().run_line_magic('clear', '')
def f():
    print('I\'m going to print something!')
    print()
    
def f(*args):
    print('I\'m going to print something!')
    print(*args)
    
f(1, 2, 3)
def f(*args):
    print(type(*args))
    
f(1)
f(1, 2)
get_ipython().run_line_magic('clear', '')
def f(*args, **kwargs):
    pass
get_ipython().run_line_magic('clear', '')
set(range(10))
set([1, 1, 1])
d = {}
d[1] = 'hello'
d[0] = []
d[[]] = 0
a = []
d[a] = 1
a.append(0)
import random
a = [random.randint(0, 1000000) for _ in range(1000)]
get_ipython().run_line_magic('clear', '')
a
get_ipython().run_line_magic('clear', '')
type(a)
b = [random.randint(0, 1000000) for _ in range(1000)]
get_ipython().run_line_magic('clear', '')
a = list(set(a))
b = list(set(b))
len(set(a) & set(b))
c = 0
for x in b:
    if x in b:
        c += 1
        
for x in b:
    if x in a:
        c += 1
        
get_ipython().run_line_magic('clear', '')
c = 0
for x in b:
    if x in a:
        c += 1
        
c
b = [random.randint(0, 1000000) for _ in range(1000000)]
a = [random.randint(0, 1000000) for _ in range(1000000)]
get_ipython().run_cell_magic('time', '', 'len(set(a) & set(b))')
get_ipython().run_cell_magic('time', '', 'for x in b:\n    if x in a:\n        c += 1\n        ')
0 in a
get_ipython().run_cell_magic('time', '', '0 in a')
set_a = set(a)
get_ipython().run_cell_magic('time', '', '0 in set_a\n')
get_ipython().run_cell_magic('time', '', 'set_a = set(a)\n0 in set_a\n')
get_ipython().run_cell_magic('time', '', 'len(set(a) & set(b))')
set_a = set(a)
get_ipython().run_cell_magic('time', '', 'c = 0\nfor x in b:\n    if x in set_a:\n        c += 1')
True + True
True + True + True
d = [1 for x in b if x in set_a]
len(d)
a = [random.randint(0, 1000000) for _ in range(1000000)]
b = [random.randint(0, 1000000) for _ in range(1000000)]
a = set(a)
b = set(b)
a = list(a)
b = list(b)
set_a = set(a)
d = [1 for x in b if x in set_a]
len(d)
sum(*d)
sum(d)
sum(int(x in set_a) for x in b)
sum(1 for x in b if x in set_a)
print('hello', end='')
def f(*args, **kwargs):
    print(type(args), type(kwargs))
    print(*args, **kwargs)
    
f('hello', end='')
def f(*args, **kwargs):
    print(args, kwargs)
    print(type(args), type(kwargs))
    print(*args, **kwargs)
    
f('hello', end='')
d = {'end': ''}
print('hello', **d)
kwargs = {'end': '???', 'sep': '___'}
args = ('hello', 'wrolds')
print(*args, **kwargs)
get_ipython().run_line_magic('clear', '')

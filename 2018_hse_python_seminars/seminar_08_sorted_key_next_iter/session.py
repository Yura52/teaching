clear
clear
max(range(5))
clear
max(range(5), key=lambda x: -x)
a = []
f = lambda x: a.append(x)
f(1)
a
f(1)
a
clear
a = 0
f = lambda x: print(a)
f(None)
a = 1
f(None)
list(map(lambda x: x * 2, range(5)))
?sorted
clear
def f(line):
    line = line.split()
    return line[0], int(line[1])
'  asd   '.strip()
a = [1, 2, 6, 10]
sorted(range(len(a)), key=lambda x: a[x])
class A:
    x = 0
    y = 1
class A:
    def __init__(self):
        print('hello')
class A:
    x = 0
    y = 1
A()
class A:
    def __init__(self):
        print('hello')
A()
class A:
    x = 0
    y = 1
class B:
    def __init__(self, x, y):
        self.x = x
        self.y = y
class A:
    x = 0
    y = 1
class A:
    x = 0
class B:
    def __init__(self, x=0):
        self.x = x
a = A()
b = B()
a.x
b.x
a1 = A()
a1.x
a1.x = 1
a.x
class A:
    x = []
a1 = A()
a2 = A()
a1.x.append(1)
a2
a2.x
class B:
    def __init__(self, x=0):
        self.x = x
B(1231231231231).x is B(12312312312313).x
class A:
    x = 0
A().x is A().x
class A:
    x = 12312763127635167253
A().x is A().x
a = list(range(5))
it = iter(a)
id(it)
id(a)
b = map(int, a)
it_b = iter(b)
b is it_b
b.__next__()
b.__next__()
b.__next__()
b.__next__()
b.__next__()
b.__next__()

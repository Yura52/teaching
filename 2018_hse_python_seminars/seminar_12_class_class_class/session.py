# coding: utf-8
get_ipython().run_line_magic('clear', '')
int
str
float
a = 1
b = 1.0
c = 'abc'
get_ipython().run_line_magic('clear', '')
int, float, str
int()
float()
str()
int(1)
float('1.0')
str(5 + 5)
isinstance(5, int)
class Student:
    def __init__(self, name: str) -> None:
        self.name = name
        
class Student:
    def __init__(self, name: str) -> None:
        self.name = name
        
a = Student('Ivan')
b = Student('John')
a.name
b.name
a = Student('Mark')
a.name = 'Vitalik'
a.name
b.name
a.name = 5
get_ipython().run_line_magic('clear', '')
class Student:
    def __init__(self, name: str) -> None:
        self.name = name
        
class Student:
    def __init__(self, name: str) -> None:
        self.name = name
    def get_name(self) -> str:
        return self.name
    
a = Student('Ivan')
a.get_name()
a
class Student:
    def __init__(self, name: str) -> None:
        self.name = name
    def get_name(self) -> str:
        return self.name
    def set_name(self, name: str) -> None:
        self.name = name
        
class Student:
    def __init__(self, name: str) -> None:
        self.name = name
    def get_name(self) -> str:
        return self.name
    def set_name(self, new_name: str) -> None:
        self.name = new_name
        
a = Student('Ivan')
a
a.name
a.get_name()
a.set_name('Dima')
a.get_name()
class Student:
    def __init__(self, name: str) -> None:
        self.name = name
    def get_name(self) -> str:
        return self.name
    def set_name(self, new_name: str) -> None:
        self.name = new_name
        
a = Student('Ivan')
a.wei
a.weight
a.weight = 50
class Student:
    def __init__(self, name: str) -> None:
        self.name = name
    def get_name(self) -> str:
        return self.name
    def set_name(self, new_name: str) -> None:
        self.name = new_name
        
a = Student('Ivan')
print(a)
str(a)
class Student:
    def __init__(self, name: str) -> None:
        self.name = name
    def get_name(self) -> str:
        return self.name
    def set_name(self, new_name: str) -> None:
        self.name = new_name
    def __str__(self) -> str:
        return f'Studen(name={self.name})'
    
class Student:
    def __init__(self, name: str) -> None:
        self.name = name
    def get_name(self) -> str:
        return self.name
    def set_name(self, new_name: str) -> None:
        self.name = new_name
    def __str__(self) -> str:
        return f'Student(name={self.name})'
    
class Student:
    def __init__(self, name: str) -> None:
        self.name = name
    def get_name(self) -> str:
        return self.name
    def set_name(self, new_name: str) -> None:
        self.name = new_name
    def __str__(self) -> str:
        return f'Student(name={self.name})'
    # def __str__(self) -> str:
      #   return 'Student ' + str(self.name)
      
a = Student('Ivan')
str(a)
print(a)
class Matrix:
    def __init__(self, data):
        self.data = copy.deepcopy(data)
    def size(self):
        return len(self.data), len(self.data[0])
    def __str__(self) -> str:
        return '\t'.join(map(str, self.data[0]))
    
m = Matrix([[0, 1], [0, 2]])
get_ipython().run_line_magic('clear', '')
import copy
class Matrix:
    def __init__(self, data):
        self.data = copy.deepcopy(data)
    def size(self):
        return len(self.data), len(self.data[0])
    def __str__(self) -> str:
        return '\t'.join(map(str, self.data[0]))
    
m = Matrix([[0, 1], [0, 2]])
str(m)
print(m)
['a', 'b', 'c']
p = ['a', 'b', 'c']
'ZZZZZ'.join(p)
for x in range(3):
    print(x)
    
'***'.join(range(3))
'***'.join(map(str, range(3)))
class Matrix:
    def __init__(self, data):
        self.data = copy.deepcopy(data)
    def size(self):
        return len(self.data), len(self.data[0])
    def __str__(self) -> str:
        return '\t'.join(map(str, self.data[0]))
    
class Matrix:
    def __init__(self, data):
        self.data = copy.deepcopy(data)
    def size(self):
        return len(self.data), len(self.data[0])
    def __str__(self) -> str:
        rows = ['0\t1', '2\t3']
        rows = [
            '\t'.join(map(str, x))
            for x in self.data
        ]
        return str(rows)
    
    
m = Matrix([[0, 1], [0, 2]])
print(m)
rows = []
for x in self.
class Matrix:
    def __init__(self, data):
        self.data = copy.deepcopy(data)
    def size(self):
        return len(self.data), len(self.data[0])
    def __str__(self) -> str:
        rows = [
            '\t'.join(map(str, x))
            for x in self.data
        ]
        return str(rows)
    def h(self):
        print('hello')
    def m(self):
        self.h()
    
m = Matrix([[0, 1], [0, 2]])
m.m()
class Matrix:
    def __init__(self, data):
        self.data = copy.deepcopy(data)
    def size(self):
        return len(self.data), len(self.data[0])
    def __str__(self) -> str:
        rows = [
            '\t'.join(map(str, x))
            for x in self.data
        ]
        return str(rows)
    def h(self):
        print('hello')
    def m(self):
        self.h()
    
get_ipython().run_line_magic('save', 'sesssssss \\0')
get_ipython().run_line_magic('save', 'sesssssss ~0')
get_ipython().run_line_magic('save', 'sesssssss ~0/')

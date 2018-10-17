# try to run this script


class Student:
    def __init__(self, name: str) -> None:
        self._name = name

    def get_name(self) -> str:
        return self._name

    def set_name(self, new_name: str) -> None:
        self._name = new_name

    def get_info(self) -> str:
        return f'Student(name={self.get_name()}), id={id(self)}'

    def __str__(self) -> str:
        return f'Student(name={self.get_name()})'


s = Student('Ivan')
print('s = Student(\'Ivan\')')
print('[s.get_name()]', s.get_name())
s.set_name('John')
print('[s.set_name(`John`)]')
print('[s.get_name()]', s.get_name())
print('[id(s)]', id(s))
print('[s.get_info()]', s.get_info())
print('[s]', s)  # here, s.__str__ is called

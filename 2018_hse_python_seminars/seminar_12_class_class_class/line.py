# try to run this script


class Line:
    def __init__(self, k: float, b: float) -> None:
        self._k = k
        self._b = b

    def __call__(self, x: float) -> float:
        return self._k * x + self._b

    def get_k(self) -> float:
        return self._k

    def get_b(self) -> float:
        return self._b

    def __str__(self) -> str:
        return f'Line [y = {self.get_k()}x + {self.get_b()}]'

    def __add__(self, other: 'Line') -> 'Line':
        # above, we have to put `Line` in quotes in Python <= 3.6,
        # because we have not finished the definition of the class
        # and the interpreter doesn't know about the class Line now.
        # Python 3.7 is smarter and you can use Line without quotes in the
        # above declaration:
        # def __add__(self, other: Line) -> Line:
        return Line(self.get_k() + other.get_k(), self.get_b() + other.get_b())


p = Line(2, 3)
print('p:', p)
q = Line(-4, 7)
print('q:', q)
r = p + q
print('r = p + q:', r)

# try to run this script
from typing import Any, Optional


class LineException(Exception):
    def __init__(self, message: str, bad_greeting: Any) -> None:
        super().__init__(message)
        self._bad_greeting = bad_greeting


class Line:
    def __init__(self, k: float, b: float) -> None:
        self._k = k
        self._b = b

    def __call__(self, x: float) -> float:
        return Line.calculate(self._k, self._b, x)
    
    @staticmethod  # it's better to create a function than a staticmethod
    def calculate(k, b, x):
        return k * x + b


class GreetingLine(Line):
    def __call__(self, x: float, greeting: Optional[str]=None) -> float:
        if greeting is not None:
            if not isinstance(greeting, str):
                message = (
                    f'greeting must be of the type `str`, '
                    f'but greating == {greeting} '
                    f'and type({greeting}) is {type(greeting)}'
                )
                raise LineException(message, greeting)
            print(greeting)
        return super().__call__(x)


line = GreetingLine(2, 3)
print('=== line(5) ===')
print(line(5))
print('=== line(5, \'Goodbye\') ===')
print(line(5, 'Goodbye'))
print('=== Line.calculate(-1, 2, 8): ===')
print(Line.calculate(-1, 2, 8))
print('=== line(5, 1.0): ===')
print(line(5, 1.0))

class Map:
    def __init__(self, function, iterable):
        self._function = function
        self._iterator = iter(iterable)

    def __iter__(self):
        return self

    def __next__(self):
        try:
            return self._function(next(self._iterator))
        except StopIteration:
            raise StopIteration

x = Map(lambda x: x * 2, range(5))
print(f'1. list(x): {list(x)}')
print(f'2. list(x): {list(x)}')

a, b = Map(int, ['1', '2'])
print(f'a + b = {a + b}')

# try to run this script


class OnePassTuple:
    def __init__(self, data):
        self._data = data
        self._index = 0
        self._max_index = len(self._data) - 1

    def __iter__(self):
        return self

    def __next__(self):
        if self._index > self._max_index:
            raise StopIteration
        value = self._data[self._index]
        self._index += 1
        return value


strange_tuple = OnePassTuple(('a', 'b', 'c'))
print(list(strange_tuple))
print(list(strange_tuple))

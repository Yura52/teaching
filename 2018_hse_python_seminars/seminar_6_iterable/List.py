# start reading from List, then go to ListIterator, then to StrangeList


class ListIterator:
    def __init__(self, list_):
        self._list = list_
        self._index = 0
        self._max_index = len(list_) - 1

    def __next__(self):
        print(f'[__next__] iterator {id(self)} list {id(self._list)}')
        if self._index > self._max_index:
            raise StopIteration
        value = self._list[self._index]
        self._index += 1
        return value


class List:
    def __init__(self, data):
        self._data = data

    # __len__ makes it possible to apply `len`
    def __len__(self):
        return len(self._data)

    # __getitem__ makes is possible to apply `[]`
    def __getitem__(self, index):
        return self._data[index]

    def __iter__(self):
        iterator = ListIterator(self)
        print(f'[__iter__] iterator {id(iterator)} list {id(self)}')
        return iterator


class StrangeTuple:
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


for x in List([1, 2, 3]):
    print(x)

strange_tuple = StrangeTuple(('a', 'b', 'c'))
print(list(strange_tuple))
print(list(strange_tuple))

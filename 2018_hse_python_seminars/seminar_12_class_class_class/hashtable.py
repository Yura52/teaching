import itertools


class Item:
    def __init__(self, value):
        self._value = value

    def get_value(self):
        return self._value

    def __str__(self):
        return f'Item(value={self.get_value()})'


class Set:
    # It's a very simple, non-efficient implementation
    def __init__(self, iterable):
        self.clear()
        for x in iterable:
            self.add(x)

    def clear(self):
        self._data = [None]
        self._size = 0

    def _get_values(self):
        return [x.get_value() for x in self._data if x is not None]

    def _calculate_index(self, value):
        return hash(value) % len(self._data)

    def _insert_by_index(self, value, index):
        success = False
        if self._data[index] is None:
            # no element here, let's add it!
            self._data[index] = Item(value)
            self._size += 1
            return True
        elif self._data[index].get_value() == value:
            # such element already exist!
            return True
        else:
            # the place with such index is already occupied by other value
            return False

    def _resize(self):
        values = self._get_values()
        old_length = len(self._data)
        self.clear()
        self._data = [None for _ in range(old_length * 2)]
        for x in values:
            self.add(x)

    def _get_index_candidates(self, initial_index):
        return itertools.chain(
            range(initial_index, len(self._data)),
            range(0, initial_index)
        )

    def add(self, value):
        if len(self._data) == self._size:
            self._resize()
        initial_index = self._calculate_index(value)
        for index in self._get_index_candidates(initial_index):
            if self._insert_by_index(value, index):
                return

    def __str__(self):
        data = ' '.join(map(str, self._data))
        return f'Set([{data}])'

    def __len__(self):
        return self._size

    def __contains__(self, value):
        initial_index = self._calculate_index(value)
        for i in self._get_index_candidates(initial_index):
            if self._data[i] is None:
                return False
            if self._data[i].get_value() == value:
                return True
        return False

s = Set([1, 2, 3])
print(s)
1 in s

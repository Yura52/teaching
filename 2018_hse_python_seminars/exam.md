# Самый главный принцип: ВБХ
Все будет хорошо.


# Общие советы

### 0. Не тратьте время на тупление в монитор
Если решение не пришло вам в голову быстро и вы начали чувстовать затуп, отложите ноут и
попробуйте решить задачу абстрактно, с ручкой и бумажкой.
И помните: от вас не будут хотеть ничего сложного.

### 1. Иногда задачи решаются перебором разных методов
Пусть задача не решается сходу. Попробуйте последовательно вспомнить все, чему учили:
может есть смысл посортировать что-нибудь, а может имеет смысл сделать словарь, 
а может уместно использовать множества и т.д.  
P.S. Такой подход прокатывает даже на собеседованиях :)


# Полезные ссылки
`built-ins`: https://docs.python.org/3/library/functions.html (эта страница содержит документацию
по целой куче знакомых вам функций: `sorted`, `max`, `min`, `all`, `any` и многим другим)

`dict`: https://docs.python.org/3/library/stdtypes.html#mapping-types-dict  
`set`: https://docs.python.org/3/library/stdtypes.html#set  
`str`: https://docs.python.org/3/library/stdtypes.html#string-methods  
`list`: https://docs.python.org/3/tutorial/datastructures.html#more-on-lists  
`file`: https://docs.python.org/3/tutorial/inputoutput.html#methods-of-file-objects

`itertools`: https://docs.python.org/3/library/itertools.html  
`math`: https://docs.python.org/3/library/math.html

`class`:
- https://github.com/StrausMG/teaching/tree/master/2018_hse_python_seminars/seminar_12_class_class_class
- https://github.com/StrausMG/teaching/tree/master/2018_hse_python_seminars/seminar_13_inheritance_exception
- <ваши решения 12-го контеста>


# Организационные моменты

### 0. Ввод, вывод
Я уточнил у лектора: ввод и вывод во всех задачах можно организовывать так, как вам удобно,
то есть для ввода используете что хотите из `input`/`sys.stdin`/`'input.txt'`, для вывода
что хотите из `print`/`sys.stdout`/`'output.txt'`.

### 1. Во всех задачах можно использовать все ваши знания
То есть в задаче про светофор из демо-экзамена можно использовать хоть функциональное
программирование, ограничений нет (разумеется, за исключением явных запретов очередных
читерских функций из `itertools`, о которых будет написано в условии или объявлено
дополнительно).

### 2. За нарушение запретов решение будет баниться
Если в условии задачи явно сказано о запрете использовать какую-то функцию
или какой-то модуль, но вы заиспользовали, то решение не будет засчитано.
Решайте экзамен честно.

### 3. За "плохой стиль" и какие-либо извращения решения не будут баниться
Но называя переменные `a1`, `a2`, `a3` и т.д., будьте готовы опечататься и дебажить
WA, RE и т.д. :)


# Хозяйке на заметку

### 0. Итерируясь по файлам (например, по sys.stdin), делайте `rstrip('\n')`
Для верности, можете начинать задачу так...
```python
>>> import sys
>>> lines = map(lambda x: x.rstrip('\n'), sys.stdin)
```
... и после этого, итерируясь по `lines` вместо `sys.stdin`, вы будете получать
уже пострипанные строки.

### 1. Считывайте ровно столько строк, сколько сказано
Если первой строкой идет `N` - число, скажем, имен студентов, а потом `N` строк,
содержащих эти имена, то порой действительно важно считать ровно `N` имен. Дело в
том, что иногда может быть нарушено условие и вам в качестве `N+1`-го имени
придет пустая строчка. А это в свою очередь может сломать какое-то ваше решение и
приводить к RE. Как это побороть:
```python
>>> import itertools
>>> import sys
>>> name_count = int(sys.stdin.readline())
>>> lines = itertools.islice(sys.stdin, name_count)
```
Теперь `lines` выдаст вам ровно `name_count` строк.

### 2. У меня есть iterable `X`, хочу взять первый элемент
Нужно взять итератор от `X` и позвать для него `next`. В одну строчку так:
```python
>>> first_item = next(iter(X))
```
Это сработает для абсолютно любого iterable, хоть многопроходного (`list`/`tuple`/`set` и т.д.), хоть
однопроходного (`map`/`filter`/`zip`/`reversed` и т.д.). Но помните две вещи:
- если iterable у вас однопроходный, то строчка выше потратит его первый элемент
и следующий цикл for будет выдавать только элементы, начиная со второго.
- если `X` - пустой iterable, то вам прилетит исключение StopIteration, так что если
такая вероятность есть, воспользуйтесь `try`/`except`:
```python
>>> try:
...     first_item = next(iter(X))
... except StopIteration:
...     <тут код на случай пустого `X`>
```

### 3. Как взять любой элемент из `set`?
`set` - iterable, так что достаточно воспользоваться рецептом из предыдущего пункта.

### 4. Уделите вниманию типу `my_collection` на случай `if my_value in my_collection`
Этот `if` будет работать линейное время для `list`/`tuple` и будет работать мгновенно для
`set`, `dict`.

### 5. Не делайте повторных вычислений
Это может привести к TL. Например, вот так плохо, потому что максимум значений словаря
вычисляется заново на каждой итерации вашего цикла:
```python
>>> my_dict = ...
>>> for x in my_collection:
...     if x > max(my_dict.values()):
...         do_something()
```
Запомните максимум вне цикла и уже потом используйте:
```python
>>> my_dict = ...
>>> max_value = max(my_dict.values())
>>> for x in my_collection:
...     if x > max_value:
...         do_something()
```
Разумеется, это касается не только поиска максимума среди значений словаря.
Это касается всех операций, у которых не мгновенная скорость выполнения: если ее результат
используется в цикле, то запомните этот результат вне цикла в отдельной переменной, а в цикле
используйте эту переменную.
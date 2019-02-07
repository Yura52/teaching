# 1.B
```c++
std::vector<i32>::iterator Find(??? first, ??? last, i32 value);
```

# 1.C
```c++
template<???>
??? Find(??? first, ??? last, ??? value);
```
Добавить поддержку векторов любого типа, не только `int`.

# 1.D
```c++
template<???>
??? Find(??? first, ??? last, ??? value);
```
Добавить поддержку любых итераторов, а не только итераторов вектора.

# 2.A
```c++
std::vector<i32>::iterator FindIf(const std::vector<i32>& v, ??? predicate);
```
Вернуть итератор на первый элемент `x`, такой, что `predicate(x)` равен `true`.

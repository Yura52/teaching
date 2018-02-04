#pragma once

template <typename T>
class List {
 protected:
  struct ListElem {
    ListElem *prev;
    ListElem *next;
    T *data;

    ListElem() : prev{this}, next{this}, data{nullptr} {}
    void Dump() {
      std::cout << this << ' '
                << prev << ' '
                << next << ' '
                << data << std::endl;
    }
  };

 public:
  class Iterator {
   public:
    friend class List;

    Iterator();
    Iterator(ListElem *list_elem_ptr);
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    T& operator*() const;
    T* operator->() const;

    bool operator==(const Iterator& rhs) const;
    bool operator!=(const Iterator& rhs) const;

    void Dump() {
      std::cout << this << ' '
                << list_elem_ptr_ << ' '
                << list_elem_ptr_->prev << ' '
                << list_elem_ptr_->next << ' '
                << list_elem_ptr_->data << std::endl;
    }

   private:
    ListElem *list_elem_ptr_;
  };

  List();
  List(const List&);
  List(List&&);
  ~List();

  List& operator=(const List&);
  List& operator=(List&&);

  bool IsEmpty() const;
  size_t Size() const;

  void Insert(Iterator position, const T& value);
  void Insert(Iterator position, Iterator first, Iterator last);
  void MoveInsert(Iterator position, T&& value);
  void MoveInsert(Iterator position, Iterator first, Iterator last);
  void PushBack(const T& elem);
  void PushBack(T&& elem);
  void PushFront(const T& elem);
  void PushFront(T&& elem);

  T& Front();
  const T& Front() const;
  T& Back();
  const T& Back() const;

  void Erase(Iterator position);
  void Erase(Iterator first, Iterator last);
  void PopBack();
  void PopFront();

  Iterator Begin() const;
  Iterator End() const;
  Iterator Begin();
  Iterator End();

 private:
  ListElem *end_;
  size_t size_ = 0;
};

//=== List::Iterator ==========================================================
template <typename T>
List<T>::Iterator::Iterator()
  : list_elem_ptr_(nullptr)
  {}

template <typename T>
List<T>::Iterator::Iterator(ListElem *list_elem_ptr)
  : list_elem_ptr_(list_elem_ptr)
  {}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator++() {
  list_elem_ptr_ = list_elem_ptr_->next;
  return *this;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++(int) {
  Iterator ret(*this);
  ++(*this);
  return ret;
}

template <typename T>
typename List<T>::Iterator& List<T>::Iterator::operator--() {
  list_elem_ptr_ = list_elem_ptr_->prev;
  return *this;
}

template <typename T>
T& List<T>::Iterator::operator*() const {
  return *((*list_elem_ptr_).data);
}

template <typename T>
T* List<T>::Iterator::operator->() const {
  return (*list_elem_ptr_).data;
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& other) const {
  return list_elem_ptr_->data == other.list_elem_ptr_->data;
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const {
  return list_elem_ptr_->data != other.list_elem_ptr_->data;
}

//=== List ====================================================================
template <typename T>
List<T>::List():
  end_{new ListElem},
  size_{0}
  {}

template <typename T>
List<T>::List(const List& other):
  end_{new ListElem},
  size_{0} {
  Insert(Begin(), other.Begin(), other.End());
}

template <typename T>
List<T>::List(List&& other)
  : end_{new ListElem},
    size_{0} {
  MoveInsert(Begin(), other.Begin(), other.End());
}

template <typename T>
List<T>::~List() {
  Erase(Begin(), End());
  delete end_;
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
  Erase(Begin(), End());
  Insert(Begin(), other.Begin(), other.End());
  return *this;
}

template <typename T>
List<T>& List<T>::operator=(List<T>&& other) {
  Erase(Begin(), End());
  MoveInsert(Begin(), other.Begin(), other.End());
  return *this;
}

template <typename T>
bool List<T>::IsEmpty() const {
  return size_ == 0;
};

template <typename T>
size_t List<T>::Size() const {
  return size_;
}

template <typename T>
void List<T>::Insert(Iterator position, const T& value) {
  ListElem *new_elem = new ListElem;
  new_elem->prev = position.list_elem_ptr_->prev;
  new_elem->next = position.list_elem_ptr_;
  position.list_elem_ptr_->prev->next = new_elem;
  position.list_elem_ptr_->prev = new_elem;
  T *new_data = new T(value);
  new_elem->data = new_data;
  ++size_;
}

template <typename T>
void List<T>::Insert(Iterator position, Iterator first, Iterator last) {
  for (auto iter = first; iter != last; ++iter) {
    Insert(position, *iter);
  }
}

template <typename T>
void List<T>::MoveInsert(Iterator position, T&& value) {
  ListElem *new_elem = new ListElem;
  new_elem->prev = position.list_elem_ptr_->prev;
  new_elem->next = position.list_elem_ptr_;
  position.list_elem_ptr_->prev->next = new_elem;
  position.list_elem_ptr_->prev = new_elem;
  T *new_data = new T(std::move(value));
  new_elem->data = new_data;
  ++size_;
}

template <typename T>
void List<T>::MoveInsert(Iterator position, Iterator first, Iterator last) {
  for (auto iter = first; iter != last; ++iter) {
    MoveInsert(position, std::move(*iter));
  }
}

template <typename T>
void List<T>::PushBack(const T& value) {
  Insert(End(), value);
}

template <typename T>
void List<T>::PushBack(T&& value) {
  MoveInsert(End(), std::move(value));
}

template <typename T>
void List<T>::PushFront(const T& value) {
  Insert(Begin(), value);
}

template <typename T>
void List<T>::PushFront(T&& value) {
  MoveInsert(Begin(), std::move(value));
}

template <typename T>
T& List<T>::Front() {
  return *Begin();
}

template <typename T>
const T& List<T>::Front() const {
  return *Begin();
}

template <typename T>
T& List<T>::Back() {
  return *--End();
}

template <typename T>
const T& List<T>::Back() const {
  return *--End();
}

template <typename T>
void List<T>::Erase(Iterator position) {
  delete position.list_elem_ptr_->data;
  position.list_elem_ptr_->prev->next = position.list_elem_ptr_->next;
  position.list_elem_ptr_->next->prev = position.list_elem_ptr_->prev;
  delete position.list_elem_ptr_;
  --size_;
}

template <typename T>
void List<T>::Erase(Iterator first, Iterator last) {
  for (auto iter = first; iter != last; ++iter) {
    Erase(iter);
  }
}

template <typename T>
void List<T>::PopBack() {
  Erase(--End());
}

template <typename T>
void List<T>::PopFront() {
  Erase(Begin());
}

template <typename T>
typename List<T>::Iterator List<T>::Begin() const {
  return Iterator(end_->next);
}

template <typename T>
typename List<T>::Iterator List<T>::End() const {
  return Iterator(end_);
}

template <typename T>
typename List<T>::Iterator List<T>::Begin() {
  return Iterator(end_->next);
}

template <typename T>
typename List<T>::Iterator List<T>::End() {
  return Iterator(end_);
}

//=== Other ===================================================================
template <typename T>
typename List<T>::Iterator begin(List<T>& list) {
  return list.Begin();
}

template <typename T>
typename List<T>::Iterator end(List<T>& list)  {
  return list.End();
}

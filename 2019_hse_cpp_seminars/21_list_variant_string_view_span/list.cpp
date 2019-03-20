#include <cstdlib>

template <typename T>
class List {
private:
    struct Node;

public:
    using value_type = T;
    using pointer = value_type*;
    using const_reference = const value_type&;

    class Iterator {
        friend class List;

    private:
        Node* ptr_{nullptr};
    };

public:
    void insert(Iterator position, const_reference value) {
        Node* node = new Node;
        node->prev = position.ptr_->prev;
        node->next = position.ptr_;
        position.ptr_->prev->next = node;
        position.ptr_->prev = node;
        pointer new_data = new value_type(value);
        node->data = new_data;
        ++size_;
    }

private:
    struct Node {
        Node()
            : prev{this}, next{this}
        {}

        Node* prev{nullptr};
        Node* next{nullptr};
        pointer value{nullptr};
    };

    Node* end_{nullptr};
    size_t size_{0};
};

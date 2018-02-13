template<class T>
struct remove_reference {
    using type = T;
};

template<class T>
struct remove_reference<T&> {
    using type = T;
};

template<class T>
struct remove_reference<T&&> {
    using type = T;
};

int main() {

    return 0;
}

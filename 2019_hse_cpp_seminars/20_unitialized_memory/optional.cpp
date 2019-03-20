template<typename T>
class Optional {
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;

    const const_reference& value() const;

private:
    bool has_value_{false};
    alignas(value_type) char value_[sizeof(value_type)];
};

template<typename T>
Optional<T>::const_reference Optional<T>::value() const {
    return *reinterpret_cast<Optional<T>::const_pointer>(value_);
}

class OptionalInt {
    const int& value() const {
        return reinterpret_cast<const int&>(value_);
    }

private:
    bool has_value_{false};
    alignas(int) char value_[sizeof(int)];
};

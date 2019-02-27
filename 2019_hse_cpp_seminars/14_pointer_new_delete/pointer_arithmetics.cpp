#include <iostream>
#include <cstdint>

using i32 = int32_t;

bool IsMultipleOfEight(i32* ptr) {
    return !reinterpret_cast<intptr_t>(ptr);
}

template<class T>
void Print(const T& value) {
    std::cout << value << '\n';
}

class Pair {
public:
    Pair(i32 first, i32 second)
        : first_{first}, second_{second}
    {}

    i32 GetFirst() const { return first_; }
    i32 GetSecond() const { return second_; }

private:
    i32 first_{0};
    i32 second_{0};
};

std::ostream& operator<<(std::ostream& os, const Pair& pair) {
    os << "(" << pair.GetFirst() << ", " << pair.GetSecond() << ')';
    return os;
}

int main() {
    i32 a = 10, b = 20;
    i32* a_ptr = &a;
    i32* b_ptr = &b;
    Pair p(100, 200), q(400, 500);
    Pair *p_ptr = &p, *q_ptr = &q;
    i32 gap = IsMultipleOfEight(b_ptr) ? 0 : 1;

    Print(a_ptr);
    Print(b_ptr);
    Print(&a_ptr);
    Print(&b_ptr);
    Print(p_ptr);
    Print(q_ptr);
    Print(gap);
    Print("=====");

    Print(*a_ptr);
    Print(**&b_ptr);
    Print(b_ptr[0]);
    Print("=====");

    Print(*(a_ptr - 1));
    Print(*(b_ptr + 1));
    Print("=====");

    Print(*q_ptr);
    Print(q_ptr[0]);
    Print(*(q_ptr + 1));
    Print("=====");

    Print(*(reinterpret_cast<i32*>(p_ptr) - 2));
    Print(*(a_ptr - 8 - gap));
    Print(*(reinterpret_cast<Pair*>(a_ptr - 8 - gap)));

    return 0;
}

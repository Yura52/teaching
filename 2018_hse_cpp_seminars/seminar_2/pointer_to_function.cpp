#include <iostream>

int MultiplyByTwo(int number) {
    return number * 2;
}

int main() {
    // 'auto' is not used only for educational purpose!
    // syntax for pointer to function:
    // 1) write function's signature: int(int)
    // 2) add "(*)" between return type and arguments: int(*)(int)
    // 3) put the name just after "*": int(*my_pointer_to_function)(int)

    int(*my_pointer_to_function)(int) = MultiplyByTwo;
    std::cout << my_pointer_to_function(10) << '\n';

    return 0;
}

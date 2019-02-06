#include <cstdint>
#include <iostream>
#include <vector>

using i32 = int32_t;

i32 MultiplyByTwo(i32 number) {
    return number * 2;
}

// Let's suppose you want to write a sorting function that takes a function pointer to some comparator.
// For simplicity, the function is design only for `i32`.
// So, the signature is `void Sort(std::vector<i32>& v, ??? comparator)
// 
// Here is the algorithm what to write instead of `???`
// 1) write function's signature: `bool comparator(i32, i32)`
// 2) put the function name in parenthesis: `bool(comparator)(i32, i32)`
// 3) add "*" just before the function name: `bool(*comparator)(i32, i32)`
// That's it!
void Sort(std::vector<i32>& v, bool(*comparator)(i32, i32)) {
    // now you can call it as a usual function: `comparator(first, second)`
}


int main() {
    // `auto` is not used only for educational purpose!
    // syntax for pointer to function:
    // 1) write function's signature: int(int)
    // 2) add "(*)" between return type and arguments: int(*)(int)
    // 3) put the name just after "*": int(*my_pointer_to_function)(int)

    // auto transforms to `i32(*my_pointer_to_function)(i32)`, just use the algorithm above
    const auto my_function_pointer = MultiplyByTwo;
    std::cout << my_function_pointer(10) << '\n';

    return 0;
}

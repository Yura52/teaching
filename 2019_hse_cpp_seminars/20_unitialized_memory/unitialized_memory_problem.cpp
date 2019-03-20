#include <cstdint>
#include <iostream>
#include <vector>

using i32 = int32_t;

int main() {
    std::vector<i32> v = {1, 2, 3};
    char w[sizeof(v)];

    // 1. Construct default std::vector<i32> in w with placement new
    ???

    // 2. destruct the vector in w
    // w is char[], but earlier we constructed a vector in this memory.
    // The compiler does not know that! So we are responsible for calling the destructor.
    ???

    // 3. Construct a copy of v in w with placement new
    ???

    // 4. destruct the vector in w

    // 5. Move v to w with placement new
    ???

    // 6. destruct the vector in w

    // 7. Construct a vector containing ten ones: {1, 1, 1, ..., 1}
    ???

    // 8. Print the size of the vector in w
    ???

    // 9. Call the method `clear` of the vector in w
    ???

    // 10. destruct the vector in w
    ???

    return 0;
}

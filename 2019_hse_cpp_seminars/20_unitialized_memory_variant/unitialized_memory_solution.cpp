#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

using i32 = int32_t;
using Vector = std::vector<i32>;

int main() {
    Vector v = {1, 2, 3};
    char w[sizeof(v)];

    // 1.
    new (w) Vector;

    // 2.
    reinterpret_cast<Vector*>(w)->~Vector();
    // std::destroy_at(reinterpret_cast<Vector*>(w));

    // 3. Construct a copy of v in w with placement new
    new (w) Vector(v);

    // 4. destruct the vector in w
    reinterpret_cast<Vector*>(w)->~Vector();
    // std::destroy_at(reinterpret_cast<Vector*>(w));

    // 5. Move v to w with placement new
    new (w) Vector(std::move(v));

    // 6. destruct the vector in w
    reinterpret_cast<Vector*>(w)->~Vector();
    // std::destroy_at(reinterpret_cast<Vector*>(w));

    // 7. Construct a vector containing ten ones: {1, 1, 1, ..., 1}
    new (w) Vector(10, 1);

    // 8. Print the size of the vector in w
    std::cout << reinterpret_cast<Vector*>(w)->size() << '\n';

    // 9. Call the method `clear` of the vector in w
    reinterpret_cast<Vector*>(w)->clear();

    // 10. destruct the vector in w
    reinterpret_cast<Vector*>(w)->~Vector();
    // std::destroy_at(reinterpret_cast<Vector*>(w));

    return 0;
}

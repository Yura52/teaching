#include <cstdint>
#include <iostream>


using u32 = uint32_t;


/* 
    never subtract from unsigned types
*/
int main() {
    u32 a = 3;
    while (a - 1 >= 0) {
        a -= 1;
        std::cout << a << '\n';
    }

    return 0;
}

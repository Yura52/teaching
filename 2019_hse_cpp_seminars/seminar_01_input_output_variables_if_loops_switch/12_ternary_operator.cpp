#include <cstdint>
#include <iostream>


using i32 = int32_t;


int main() {
    bool condition = true;
    const auto message = condition ? 'true' : 'false';
    std::cout << message << '\n';    

    return 0;
}

#include <cstring>
#include <iostream>
#include <string>

size_t Strlen(const char* s) {
    size_t len = 0;
    for (; *s; ++s) {
        ++len;
    }
    return len;
}



int main() {
    const char* s = "abc";
    std::string r(s);
    std::cout
        << std::strlen(s) << ' '
        << Strlen(s) << ' '
        << std::strlen(r.c_str()) << '\n';

    return 0;
}

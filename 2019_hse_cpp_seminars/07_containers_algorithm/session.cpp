#include <cstdint>
#include <iostream>
#include <set>


using i32 = int32_t;


void EraseOddNumbers(std::set<i32>* s) {
    auto it = s->begin();
    while(it != s->end()) {
        if (*it % 2 == 1) {
            s->erase(it++);
            // the line above expands to these three lines:
            // auto it_prev = it;
            // ++it;
            // s->erase(it_prev);
        } else {
            ++it;
        }
    }
}


int main() {
    return 0;
}

#include <algorithm>
#include <iostream>
#include <vector>


using Iterator = std::vector<int>::iterator;


bool Equal(
    Iterator first_1, Iterator last_1,
    Iterator first_2
) {
    while (first_1 != last_1) {
        if (*first_1 != *first_2) {
            return false;
        }
    }
    return true;
}


int main() {

    return 0;
}

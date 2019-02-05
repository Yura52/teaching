#include <iostream>
#include <vector>
#include <list>


int main() {
    std::list<int> v = {10, 20, 30};
    auto iterator = v.begin();

    std::cout << "[v] ";
    std::cout << *iterator << ' ';
    *iterator = 100;
    ++iterator;

    std::cout << *iterator << ' ';
    *iterator = 200;
    ++iterator;

    std::cout << *iterator << ' ';
    *iterator = 300;
    ++iterator;

    std::cout << '\n';
    std::cout << "[iterator == v.end()] " << std::boolalpha << (iterator == v.end()) << '\n';

    std::cout << "[v] ";
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    std::cout << "[v] ";
    auto it = v.begin();
    while (it != v.end()) {
        std::cout << *it << ' ';
        ++it;
        // std::cout << *it++ << ' ';
    }
    std::cout << "\n\n";

    it = v.begin();
    std::cout << "[*std::next(it)] " << *std::next(it) << '\n';
    std::cout << "[*it] " << *it << '\n';
    std::cout << "[*std::prev(v.end())] " << *std::prev(v.end()) << '\n';
    std::cout << "[*std::next(v.begin(), 2)] " << *std::next(v.begin(), 2) << '\n';
    std::advance(it, 2);
    std::cout << "[*it after std::advance(it, 2)] " << *it << '\n';
    std::cout << "[std::distance(v.begin(), it)] " << std::distance(v.begin(), it) << '\n';
    std::advance(it, -2);
    std::cout << "[*it after std::advance(it, -2)] " << *it << '\n';

    return 0;
}

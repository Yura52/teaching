#include <algorithm>
#include <iostream>
#include <vector>
#include <set>


int main() {
    std::set<int> a = {3, 2, 1};
    std::set<int> b = {4, 3, 2};
    std::set<int> c;
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(c, c.begin()));

    std::vector<int> v = {3, 2, 1};
    std::sort(v.begin(), v.end());
    std::vector<int> w = {4, 3, 2};
    std::sort(w.begin(), w.end());
    std::vector<int> z;
    std::set_intersection(v.begin(), v.end(), w.begin(), w.end(), std::back_inserter(z));

    return 0;
}

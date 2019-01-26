#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


struct Time {
    i32 day{0};
    i32 hour{0};
    i32 minute{0};
};


std::istream& operator>>(std::istream& input_stream, Time& t) {
    input_stream >> t.day >> t.hour >> t.minute;
    return input_stream;
}


std::ostream& operator<<(std::ostream& output_stream, const Time& t) {
    output_stream << t.day << ' ' << t.hour << ' ' << t.minute;
    return output_stream;
}


int main() {
    // try to uncomment
    // Time t;
    // std::cin >> t;

    Time a{1, 2, 3};
    Time b{.day = 1, .hour = 2, .minute = 3}; // С++17-feature
    std::cout
        << "a: " << a << '\n'
        << "b: " << b << '\n';

    std::vector<Time> v;
    v.push_back(a);
    v.push_back(Time{1, 2, 3});
    v.push_back({1, 2, 3});
    // v.emplace_back(1, 2, 3); doesn't work, because there is no constructor Time(1, 2, 3);

    return 0;
}

#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


struct Time {
    i32 day{0};
    i32 hour{0};
    i32 minute{0};
};


void operator>>(std::istream& input_stream, Time& t) {
    input_stream >> t.day >> t.hour >> t.minute;
}


void operator<<(std::ostream& output_stream, const Time& t) {
    output_stream << t.day << ' ' << t.hour << ' ' << t.minute;
}


int main() {
    // try to uncomment
    // Time t;
    // std::cin >> t;

    Time a{1, 2, 3};
    Time b{.day = 1, .hour = 2, .minute = 3};

    std::vector<Time> v;
    v.push_back(a);
    v.push_back(Time{1, 2, 3});
    v.push_back({1, 2, 3});
    v.emplace_back(1, 2, 3);

    return 0;
}

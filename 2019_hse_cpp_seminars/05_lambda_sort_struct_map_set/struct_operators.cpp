#include <cstdint>
#include <iostream>
#include <vector>


using i32 = int32_t;


struct Time {
    i32 day{0};
    i32 hour{0};
    i32 minute{0};

    i32 operator()(const std::string& what) {
        if (what == "day") {
            return day;
        } else if (what == "hour") {
            return hour;
        } else if (what == "minute") {
            return minute;
        } else {
            return -1;
        }
    }
};


bool operator<(const Time& first, const Time& second) {
    return
        std::make_tuple(first.day, first.hour, first.minute) <
        std::make_tuple(second.day, second.hour, second.minute);
}


int main() {
    Time a{1, 2, 3};
    std::cout << a("day") << '\n';
    std::cout << a("hour") << '\n';
    std::cout << a("minute") << '\n';
    std::cout << a("hello") << '\n';

    std::vector<Time> v = {{1, 2, 3}, {0, 1, 2}};
    std::sort(v.begin(), v.end());
    for (const auto& x: v) {
        std::cout << x.day << ' ' << x.hour << ' ' << x.minute << '\n';
    }

    return 0;
}

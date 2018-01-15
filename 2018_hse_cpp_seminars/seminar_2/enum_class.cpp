#include <iostream>

// "enum class Color {...};" is the same as "enum class Color : int {...};"
// It's possible to put other types instead of "int", for example:
// enum class Color : size_t {...};
enum class Color {
    Red = 0,
    Green,
    Blue
};

int main() {
    // Color color{Red}; // compilation error
    Color color{Color::Red};
    switch(color) {
        case Color::Red: {
            std::cout << "Red\n";
            break;
        }
        case Color::Green: {
            std::cout << "Green\n";
            break;
        }
        case Color::Blue: {
            std::cout << "Blue\n";
            break;
        }
        default:
            std::cout << "HELLO\n";
    }

    // int color_id = Color::Red; // compilation error
    int color_id = static_cast<int>(Color::Red);
    // Color my_color = 0; // compilation error
    Color my_color = static_cast<Color>(0);

    return 0;
}

#include <iostream>
#include <fstream>

class FirstBox {
public:
    FirstBox() {}

    FirstBox operator[](size_t i) {
        std::cout << "this [" << this <<   "] operator[" << i << "]\n";
        return *this;
    }

private:
};

class SecondBox {
public:
    SecondBox() {}

    // Now it returns reference to *this, not a new object
    SecondBox& operator[](size_t i) {
        std::cout << "this [" << this <<   "] operator[" << i << "]\n";
        return *this;
    }

private:
};

int main() {
    FirstBox b1;
    b1[0][0][0][0][0][0][0];
    std::cout << "\n" << std::endl;
    SecondBox b2;
    b2[0][0][0][0][0][0][0];

    return 0;
}

#include <iostream>
#include <string>
#include <vector>

class Mammal {
public:
    virtual std::string voice() const {
        return "Not implemented yet\n";
    }
};

class Cat : public Mammal {
public:
    std::string voice() const override {
        return "meow\n";
    }

private:
    size_t age{0};
};

class Dog : public Mammal {
public:
    std::string voice() const override {
        return "Waff!\n";
    }

private:
    std::string name;
};

int main() {
    Cat c;
    Dog d;
    
    std::cout << "sizeof(Mammal): " << sizeof(Mammal) << '\n';
    std::cout << "sizeof(c): " << sizeof(c) << '\n';
    std::cout << "sizeof(d): " << sizeof(d) << '\n';

    std::vector<Mammal> zoo;
    zoo.push_back(c);
    zoo.push_back(d);

    std::cout << "sizeof(zoo[0]): " << sizeof(zoo[0]) << '\n';
    std::cout << "sizeof(zoo[1]): " << sizeof(zoo[1]) << '\n';

    std::cout << zoo[0].voice();
}

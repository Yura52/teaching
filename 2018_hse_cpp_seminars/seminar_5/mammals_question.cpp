#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Mammal {
public:
    virtual string voice() const {
        return "Not implemented yet\n";
    }
};

class Cat : public Mammal {
public:
    string voice() const override {
        return "meow\n";
    }

private:
    size_t age{0};
};

class Dog : public Mammal {
public:
    string voice() const override {
        return "Waff!\n";
    }

private:
    std::string name;
};

int main() {
    Cat c;
    Dog d;

    vector<Mammal*> zoo;
    zoo.push_back(&c);
    zoo.push_back(&d);

    cout << zoo[0]->voice();
}

#include <iostream>
#include <string>


class Chat {
public:
    Chat() = default;

    explicit Chat(const std::string& name)
        : name_{name}
    {}

    Chat(const Chat& other)
        : name_{other.name_} {
        std::cout << "Copy!\n";
    }

    Chat& operator=(const Chat& other) {
        std::cout << "Assignment!\n";
        name_ = other.name_;
        return *this;
    }

    std::string GetName() const {
        return name_;
    }

    void SetName(const std::string& name) {
        name_ = name;
    }

private:
    std::string name_;
};


int main() {
    Chat a("BPMI186-2 OIMP");
    Chat b("Bandits");
    a = b;
    std::cout << a.GetName() << '\n';

    return 0;
}

#include <iostream>
#include <string>


class Chat {
public:
    Chat() = default;

    explicit Chat(const std::string& name)
        : name_{name}
    {}

    ???

    const std::string& GetName() const {
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
    a = b; // must print "Assignment!\n"
    std::cout << a.GetName() << '\n';

    return 0;
}

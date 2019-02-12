#include <iostream>
#include <string>


class Chat {
public:
    Chat() = default;

    explicit Chat(const std::string& name)
        : name_{name}
    {}

private:
    std::string name_;
};


int main() {
    Chat a;
    Chat b("BPMI186-2 OIMP");

    return 0;
}

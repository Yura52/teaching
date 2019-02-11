#include <iostream>
#include <string>


class Chat {
public:
    Chat() = default;

    explicit Chat(const std::string& name)
        : name_{name}
    {}

    ???

    std::string GetName() const {
        return name_;
    }

    void SetName(const std::string& name) {
        name_ = name;
    }

private:
    std::string name_;
};


void PrintChatName(Chat chat) {
    std::cout << chat.GetName() << '\n';
}


int main() {
    Chat a("BPMI186-2 OIMP");
    std::cout << a.GetName() << '\n';

    Chat b(a); // must print "Copy!\n"
    std::cout << b.GetName() << '\n';

    auto c = a; // must print "Copy!\n"
    std::cout << c.GetName() << '\n';

    return 0;
}

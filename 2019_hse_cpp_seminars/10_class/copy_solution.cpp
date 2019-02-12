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

    // More elegant solution:
    // Chat(const Chat& other) {
    //     std::cout << "Copy!\n";
    //     *this = other;
    // }

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

    Chat b(a);
    std::cout << b.GetName() << '\n';

    auto c = a; // the same as `Chat c(a);
    std::cout << c.GetName() << '\n';

    PrintChatName(a);

    return 0;
}

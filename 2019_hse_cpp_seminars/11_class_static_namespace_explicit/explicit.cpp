#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using i64 = int64_t;

struct Message {
    i64 sender_id{0};
    std::string text;
};

i64 GenerateId() {
    static i64 x = -1;
    ++x;
    return x;
}

class Chat {
public:
    Chat() = default;

    Chat(const Chat& other) {
        *this = other;
    }

    Chat(const std::string& name)
        : name_{name}
    {}

    Chat& operator=(const Chat& other) {
        name_ = other.name_;
        messages_ = other.messages_;
        return *this;
    }

private:
    const i64 id_{GenerateId()};
    std::string name_;
    std::vector<Message> messages_;
};


int main() {
    const std::string first_chat_name = "BPMI186-2 OIMP";
    const std::string second_chat_name = "Bandints";
    Chat first_chat(first_chat_name);
    Chat second_chat(second_chat_name);
    // ... many lines of code ...
    first_chat = second_chat_name;

    return 0;
}

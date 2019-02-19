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
    using Messages = std::vector<Message>;

    class Iterator {
    public:
        using value_type = ???

        ??? (constructor)

        bool operator!=(const Iterator& other) {
            ???
        }

        ??? operator++() {
            ???
        }

        ??? operator*() {
            ???
        }

        value_type* operator->() {
            ???
        }

    private:
        ???
    };

    Chat() = default;

    Chat(const Chat& other) {
        *this = other;
    }

    explicit Chat(const std::string& name)
        : name_{name}
    {}

    Chat& operator=(const Chat& other) {
        name_ = other.name_;
        messages_ = other.messages_;
        return *this;
    }

    const std::string& GetName() const {
        return name_;
    }

    const Messages& GetMessages() const {
        return messages_;
    }

    void SendMessage(const Message& message) {
        messages_.push_back(message);
    }

    Iterator begin() {
        return Iterator(???);
    }

    Iterator end() {
        return Iterator(???);
    }

private:
    const i64 id_{GenerateId()};
    std::string name_;
    std::vector<Message> messages_;
};


int main() {
    Chat chat("BPMI186-2 OIMP");
    chat.SendMessage({0, "Monday you can fall apart"});
    chat.SendMessage({1, "Tuesday Wednesday break my heart"});
    chat.SendMessage({2, "Oh, Thursday doesn't even start"});
    chat.SendMessage({3, "It's Friday I'm in love"});

    for (auto it = chat.begin(); it != chat.end(); ++it) {
        std::cout << it->sender_id << ' ' << it->text << '\n';
    }
    std::cout << '\n';
    for (const auto& x: chat) {
        std::cout << x.sender_id << ' ' << x.text << '\n';
    }

    return 0;
}

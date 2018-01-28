#include <iostream>
#include <string>

class ChatBase {
public:
    ChatBase() {
        std::cout << "Chat is constructed. id: " << GetChatId() << '\n';
    }

    virtual std::string GetChatId() const {
        return "default_id";
    }
};

class Chat : public ChatBase {
public:
    explicit Chat(const std::string& id)
        : id_{id}
        {}

    std::string GetChatId() const override {
        return id_;
    }

private:
    std::string id_;
};

int main() {
    Chat chat{"174-1 (Топовая)"};

    return 0;
}

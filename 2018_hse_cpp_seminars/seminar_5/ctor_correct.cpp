#include <iostream>
#include <string>

class ChatBase {
public:
    ChatBase() {}

    virtual std::string GetChatId() const {
        return "default_id";
    }

protected:
    void init() {
        std::cout << "Chat is constructed. id: " << GetChatId() << '\n';
    }
};

class Chat : public ChatBase {
public:
    static Chat ctor(const std::string& id) {
        Chat chat{id};
        chat.init();
        return chat;
    }

    std::string GetChatId() const override {
        return id_;
    }

private:
    Chat(const std::string& id)
        : id_{id}
        {}

    std::string id_;
};

int main() {
    const auto chat = Chat::ctor("174-1 (Топовая)");

    return 0;
}

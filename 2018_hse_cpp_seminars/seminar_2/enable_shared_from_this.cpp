#include <memory>
#include <vector>


class Message : public std::enable_shared_from_this<Message> {
public:
    static std::shared_ptr<Message> create(const size_t size) {
        return std::shared_ptr<Message>(new Message{size});
    }

private:
    explicit Message(const size_t size)
        : size_{size}
    {}

    size_t size_{0};
};

class MessagesGroup {
public:
    void AddMessage(Message* message) {
        messages_.push_back(message->shared_from_this());
    }

private:
    std::vector<std::shared_ptr<Message>> messages_;
};


int main() {
    return 0;
}

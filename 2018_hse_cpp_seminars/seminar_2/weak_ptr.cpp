#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>


class MessagesGroup;

class Message : public std::enable_shared_from_this<Message> {
public:
    static std::shared_ptr<Message> create(const size_t size) {
        return std::shared_ptr<Message>(new Message{size});
    }

    bool HasExpiredGroups() const {
        return std::any_of(
            std::begin(groups_),
            std::end(groups_),
            [](const auto& ptr){ return ptr.expired(); }
        );
    }

    std::shared_ptr<MessagesGroup> GetGroup(size_t index) const {
        return groups_[index].lock();
    }

private:
    using MessagesGroupPtr = std::weak_ptr<MessagesGroup>;

    explicit Message(const size_t size)
        : size_{size}
    {}

    size_t size_{0};
    std::vector<MessagesGroupPtr> groups_;
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

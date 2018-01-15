#include <array>
#include <iostream>
#include <memory>
#include <vector>


class Message {
public:
    explicit Message(const size_t size)
        : size_{size}
    {}

    virtual std::string GetTypeName() const = 0;

private:
    size_t size_{0};
};

class LargeMessage : public Message {
public:
    explicit LargeMessage(const size_t size)
        : Message{size}
    {}

    std::string GetTypeName() const override {
        return "LargeMessage";
    };

private:
    std::vector<uint8_t> data_;
};

class SmallMessage : public Message {
public:
    static constexpr size_t kSize{64};

    explicit SmallMessage(const size_t size)
        : Message{size}
    {}

    std::string GetTypeName() const override {
        return "SmallMessage";
    };

private:
    std::array<uint8_t, kSize> data_;
};

std::unique_ptr<Message> MakeMessage(const size_t size) {
    if (size >= SmallMessage::kSize) {
        return std::make_unique<LargeMessage>(size);
    } else {
        return std::make_unique<SmallMessage>(size);
    }
}

int main() {
    std::cout << MakeMessage(50)->GetTypeName() << '\n';
    std::cout << MakeMessage(150)->GetTypeName() << '\n';
    std::shared_ptr<Message>{MakeMessage(999)};

    return 0;
}

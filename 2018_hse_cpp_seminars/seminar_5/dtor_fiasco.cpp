#include <iostream>
#include <string>

class UserBase {
public:
    ~UserBase() {
        std::cout << "User is destructed. id: " << GetUserId() << '\n';
    }

    virtual std::string GetUserId() const = 0;
};

class User : public UserBase {
public:
    explicit User(const std::string& id)
        : id_{id}
        {}

    std::string GetUserId() const override {
        return id_;
    }

private:
    std::string id_;
};

int main() {
    User user{"Good Boy"};

    return 0;
}

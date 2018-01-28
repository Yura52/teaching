#include <iostream>
#include <string>

class UserBase {
public:
    virtual ~UserBase() {}

    virtual std::string GetUserId() const = 0;
};

class GoodUser : public UserBase {
public:
    explicit GoodUser(const std::string& id)
        : id_{id}
        {}
    
    ~GoodUser() override {
        std::cout << "User is destructed. id: " << GetUserId() << '\n';
    }

    std::string GetUserId() const override {
        return id_;
    }

private:
    std::string id_;
};

class BadUser : public UserBase {
public:
    explicit BadUser(const std::string& id)
        : id_{id}
        {}
    
    ~BadUser() override {
        std::cout << "User is destructed. id: " << GetUserId() << '\n';
    }

    std::string GetUserId() const override {
        return id_ + id_;
    }

private:
    std::string id_;
};

int main() {
    GoodUser guser{"Good"};
    BadUser buser{"Bad"};

    return 0;
}

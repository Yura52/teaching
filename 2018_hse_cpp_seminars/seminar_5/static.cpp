#include <iostream>
#include <memory>

class Stream {
public:
    Stream() {
        ++object_count_;
    }

    ~Stream() {
        --object_count_;
    }

    static size_t GetObjectCount() {
        return object_count_;
    }

private:
    static size_t object_count_;
};

size_t Stream::object_count_ = 0;

int main() {
    int a;

    Stream stream;
    std::cout << Stream::GetObjectCount() << '\n';

    auto uptr = std::make_unique<Stream>();
    std::cout << Stream::GetObjectCount() << '\n';
    uptr.reset();
    std::cout << Stream::GetObjectCount() << '\n';

    return 0;
}

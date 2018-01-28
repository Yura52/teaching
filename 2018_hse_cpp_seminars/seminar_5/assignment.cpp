#include <iostream>

class StreamBase {
public:
    StreamBase& operator=(const StreamBase& other) {
        std::cout << "StreamBase::operator=\n";
        return *this;
    }
};

class IStream : public StreamBase {
public:
    IStream& operator=(const IStream& other) {
        StreamBase::operator=(other);
        std::cout << "IStream::operator=\n";
        return *this;
    }
};

int main() {
    IStream first_stream;
    IStream second_stream;

    first_stream = second_stream;

    return 0;
}

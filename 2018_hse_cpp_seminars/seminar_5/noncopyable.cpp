class NonCopyable {
public:
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;

protected:
    NonCopyable() = default;
};

class IStream : private NonCopyable {};


int main() {
    IStream first_stream;
    IStream second_stream;

    IStream third_stream(first_stream);

    IStream fourth_stream;
    fourth_stream = second_stream;

    return 0;
}

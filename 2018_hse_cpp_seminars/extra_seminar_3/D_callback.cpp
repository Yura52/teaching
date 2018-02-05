#include "tokenizer.h"

#include <algorithm>
#include <iostream>
#include <string>

class TokenStatisticsRecorder : public CallbackBase {
public:
    virtual void OnToken(const char * token, size_t length) override {
        ++token_count_;
        max_token_length_ = std::max(max_token_length_, length);
    }

    size_t GetMaxTokenLength() const {
        return max_token_length_;
    }

    size_t GetTokenCount() const {
        return token_count_;
    }

private:
    size_t max_token_length_{0};
    size_t token_count_{0};
};


int main() {
    std::string line;
    std::getline(std::cin, line);

    Tokenizer tokenizer;
    TokenStatisticsRecorder recorder;
    tokenizer.Tokenize(line, &recorder);
    std::cout << recorder.GetTokenCount() << " " << recorder.GetMaxTokenLength() << '\n';

    return 0;
}

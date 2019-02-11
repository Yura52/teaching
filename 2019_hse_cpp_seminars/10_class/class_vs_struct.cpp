// THIS PROGRAM DOES NOT COMPILE AND IT IS OK!
// Try to comment/uncomment different implementations of `MessageClass`
// and see how compilation error change
#include <iostream>
#include <string>


struct MessageStruct {
    std::string body;
};


class MessageClass {
    std::string body_;
};

// 
// class MessageClass {
//     MessageClass(const std::string& body)
//         : body_{body}
//     {}

//     std::string GetBody() {
//         return body_;
//     }

//     std::string body_;
// };

// class MessageClass {
// public:
//     MessageClass(const std::string& body)
//         : body_{body}
//     {}

//     std::string GetBody() {
//         return body_;
//     }

// private:
//     std::string body_;
// };


int main() {
    MessageStruct ms{"hello"};
    MessageClass mc{"world"};
    std::cout << ms.body << '\n';
    std::cout << mc.body_ << '\n';
    std::cout << mc.GetBody() << '\n';

    return 0;
}

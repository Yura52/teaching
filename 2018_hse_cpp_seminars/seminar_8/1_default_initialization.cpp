#include <atomic>
#include <iostream>
#include <string>

class Egg {
public:
    Egg() {
        std::cout << "Egg()\n";
    }

    Egg(const Egg& other) {
        std::cout << "Egg(const Egg& other)\n";
    }

    explicit Egg(const std::string& message) {
        std::cout << "Egg(" << message << ")\n";
    }

    Egg& operator=(const Egg& other) {
        std::cout << "Egg::operator=\n";
        return *this;
    }
};

class Chicken {
public:
    Chicken() {
        std::cout << "Chicken()\n";
    }

    Chicken(const Chicken& other) {
        std::cout << "Chicken(const Chicken& other)\n";
    }

    explicit Chicken(const std::string& message) {
        std::cout << "Chicken(" << message << ")\n";
    }

    Chicken& operator=(const Chicken& other) {
        std::cout << "Chicken::operator=\n";
        return *this;
    }
};

class First {
public:
    First() {
        // Now we are at the start of the constructor's body.
        // At this moment all the fields are somehow initialized:
        // - via default initializers
        // - via list of initialization (after ":" in constructors)
        // - via default constructors (if exists)
        // - with RUBBISH if a field is of a POD-type
        std::cout << '\n';
    }

private:
    Egg e_;
    Chicken c_;
};

class Second {
public:
    Second() {
        std::cout << '\n';
    }

private:
    Chicken c_;
    Egg e_;
};

class Third {
public:
    Third() : c_{"hello"} {
        std::cout << '\n';
    }

private:
    Chicken c_;
    Egg e_;
};

class Fourth {
public:
    Fourth() : e_{"hello"} {
        std::cout << '\n';
    }

private:
    Chicken c_;
    Egg e_;
};

Chicken MakeChicken() {
    return Chicken("made by function");
}

class Fivth {
public:
    Fivth() {
        std::cout << '\n';
    }

private:
    Chicken c_ = MakeChicken();
    Egg e_{"hello"};
};

class Sixth {
public:
    Sixth() {
        std::cout << '\n';
    }

private:
    const Chicken c_ = MakeChicken();
    Egg e_{"hello"};
    // const std::atomic<int> a = 0;
    const std::atomic<int> a{0};
};

// NEVER DO THAT
// class Seventh {
// public:
//     Seventh() : e_{"hello"}, c_{"hello"} {
//         std::cout << '\n';
//     }

// private:
//     Chicken c_;
//     Egg e_;
// };

int main() {
    // First a1;
    // Second a2;
    // Third a3;
    // Fourth a4;
    // Fivth a5;
    // Sixth a6;
    // Seventh a7;

    return 0;
}

#include <iostream>
#include <fstream>

/*
Step-by-step algorithm:

1. Write 'class' + name of your class + "{}"

class Person {

};

2. Add 'public' and 'private'

class Person {
public:


private:

};

3. Add some fields

class Person {
public:


private:
    std::string name_;
    size_t age_;
};

4. Write constructors (as many as you need):

class Person {
public:
    Person() {
        std::cout << "I am a defaul constructor\n"; 
    }

    Person(const std::string& name)
        : name_(name) {
        std::cout << "I am a non-default constructor\n";
    }

private:
    std::string name_;
    size_t age_;
};

5. Write a destructor if you need:

class Person {
public:
    Person() {
        std::cout << "I am a defaul constructor\n"; 
    }

    Person(const std::string& name)
        : name_(name) {
        std::cout << "I am a non-default constructor\n";
    }

    ~Person() {
        std::cout << "I am a destructor\n";
    }

private:
    std::string name_;
    size_t age_;
};

6. Write other methods if you need:

class Person {
public:
    Person() {
        std::cout << "I am a defaul constructor\n"; 
    }

    Person(const std::string& name)
        : name_(name) {
        std::cout << "I am a non-default constructor\n";
    }

    ~Person() {
        std::cout << "I am a deconstructor\n";
    }

    void hello() {
        std::cout << "Hello\n";
        PrivateHello();
    }

private:
    void PrivateHello() {
        std::cout << "PrivateHello\n";
    }

    std::string name_;
    size_t age_;
};

*/

// Let's try!

class Person {
public:
    // Person(...);
    // ~Person();

    Person() {
        std::cout << "Person without name is constructed\n";
    }
    Person(const std::string& name)
        // : name_(some args)
        // std::string(some args)
        // : name_("Vanya")
        // std::string("Vanya")

        // std::string(name)
        : name_(name)
    {
        std::cout << "Person " << name_ << " is constructed\n";
    }

    void hello() {
        std::cout << "Hello\n";
        PrivateHello();
    }

private:
    void PrivateHello() {
        std::cout << "PrivateHello\n";
    }

    std::string name_;
};

int main() {
    Person p1;
    Person p2("Petya");
    Person p3("Vasya");

    // std::cout << p2.name_ << '\n'; // doesn't compile, because the field "name_" is in the private section
    // p2.PrivateHello(); // doesn't compile, because the method "PrivateHello" is in the private section

    return 0;
}


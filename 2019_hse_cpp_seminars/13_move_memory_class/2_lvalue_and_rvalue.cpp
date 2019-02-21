// Less rough explanation:
// If you can apply operator "&" then you work with lvalue
// In a different way you work with rvalue

int& foo(int& x) {
    return x;
}

int bar() {
    int x = 10;
    return x;
}

int main() {
    // lvalues:
    //
    int i = 42;
    i = 43; // ok, i is an lvalue
    int* p = &i; // ok, i is an lvalue
    foo(i) = 42; // ok, foo() is an lvalue
    int* p1 = &foo(i); // ok, foo() is an lvalue

    // rvalues:
    //
    int j = 0;
    j = bar(); // ok, bar() is an rvalue
    // int* p2 = &bar(); // error, cannot take the address of an rvalue
    j = 42; // ok, 42 is an rvalue

    return 0;
}

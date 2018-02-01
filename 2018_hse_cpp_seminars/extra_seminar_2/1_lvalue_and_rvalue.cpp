// A rough explanation:
// lvalue can be both on the right and on the left side of experession
// rvalue can be only on the right side of experession

int main() {
    int a = 1;
    int b = 2;

    // a, b - lvalue
    // a + b - rvalue
    a = b; // OK
    b = a; // OK
    a = a + b; // OK
    // (a + b) = a; // FAIL

    return 0;
}

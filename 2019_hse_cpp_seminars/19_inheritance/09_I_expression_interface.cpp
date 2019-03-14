#include <iostream>
#include <string>
#include <vector>
#include <memory>

using i32 = int32_t;

class Expression {
public:
    virtual i32 Evaluate() const = 0;
    virtual std::string ToString() const = 0;
    virtual ~Expression() {}
};

using ExpressionPtr = std::shared_ptr<Expression>;

class ConstExpression : public Expression {
public:
    i32 Evaluate() const override {
        return 0;
    }

    std::string ToString() const override {
        return "";
    }
};

class BinaryExpression : public Expression {
public:
    i32 Evaluate() const override {
        return 0;
    }

    std::string ToString() const override {
        return "";
    }
};

class SumExpression : public BinaryExpression {
public:
    i32 Evaluate() const override {
        return 0;
    }

    std::string ToString() const override {
        return "";
    }
};

class ProductExpression : public BinaryExpression {
public:
    i32 Evaluate() const override {
        return 0;
    }

    std::string ToString() const override {
        return "";
    }
};

ExpressionPtr Const(i32 value) {
    return nullptr;
}

ExpressionPtr Sum(const ExpressionPtr& first, const ExpressionPtr& second) {
    return nullptr;
}

ExpressionPtr Product(const ExpressionPtr& first, const ExpressionPtr& second) {
    return nullptr;
}

int main() {
    const auto a = Const(1);
    std::cout << a->ToString() << ' ' << a->Evaluate() << '\n';

    const auto b = Const(1);
    std::cout << b->ToString() << ' ' << b->Evaluate() << '\n';

    const auto c = Sum(a, b);
    std::cout << c->ToString() << ' ' << c->Evaluate() << '\n';

    const auto d = Product(a, b);
    std::cout << d->ToString() << ' ' << d->Evaluate() << '\n';

    const auto e = Sum(Product(Const(3), Const(4)), Const(5));
    std::cout << e->ToString() << ' ' << e->Evaluate() << '\n';

    return 0;
}

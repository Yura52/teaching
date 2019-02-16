class Complex {
public:
    Complex(double re, double im = 0)
        : re_{re}, im_{im}
    {}

    double Re() const {
        return re_;
    }

    double Im() const {
        return im_;
    }

private:
    double re_{0};
    double im_{0};
};

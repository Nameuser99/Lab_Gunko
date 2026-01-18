class Fraction {
private:
    int numerator;
    int denominator;
    void reduce();
    static int gcd(int a, int b);
public:
    Fraction(int num, int den);
    Fraction(const Fraction& other);
    int getNumerator() const;
    int getDenominator() const;
    Fraction plus(const Fraction& other) const;
    Fraction multiply(const Fraction& other) const;
    Fraction divide(const Fraction& other) const;
    void print() const;
};
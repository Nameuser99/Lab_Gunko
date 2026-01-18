#include "fraction.h"
#include <iostream>
#include <cstdlib>

void Fraction::reduce() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    int g = gcd(std::abs(numerator), denominator);
    numerator /= g;
    denominator /= g;
}

int Fraction::gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        std::cerr << "Error: Denominator cannot be zero!" << std::endl;
        std::exit(1);
    }
    numerator = num;
    denominator = den;
    reduce();
}

Fraction::Fraction(const Fraction& other) {
    numerator = other.numerator;
    denominator = other.denominator;
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

Fraction Fraction::plus(const Fraction& other) const {
    int new_num = numerator * other.getDenominator() + other.getNumerator() * denominator;
    int new_den = denominator * other.getDenominator();
    return Fraction(new_num, new_den);
}

Fraction Fraction::multiply(const Fraction& other) const {
    int new_num = numerator * other.getNumerator();
    int new_den = denominator * other.getDenominator();
    return Fraction(new_num, new_den);
}

Fraction Fraction::divide(const Fraction& other) const {
    if (other.getNumerator() == 0) {
        std::cerr << "Error: Cannot divide by zero!" << std::endl;
        std::exit(1);
    }
    int new_num = numerator * other.getDenominator();
    int new_den = denominator * other.getNumerator();
    return Fraction(new_num, new_den);
}

void Fraction::print() const {
    if (numerator == 0) {
        std::cout << 0;
    } else if (denominator == 1) {
        std::cout << numerator;
    } else {
        std::cout << numerator << "/" << denominator;
    }
}
#include "fraction.h"
#include <iostream>

int main() {
    Fraction f1(4, 6);
    Fraction f2(2, 3);
    Fraction f3(3, -9);
    Fraction zero(0, 7);
    Fraction whole(8, 2);

    std::cout << "f1: ";
    f1.print();
    std::cout << std::endl;

    std::cout << "f2: ";
    f2.print();
    std::cout << std::endl;

    std::cout << "f3: ";
    f3.print();
    std::cout << std::endl;

    Fraction sum_ab = f1.plus(f2);
    std::cout << "f1 + f2 = ";
    sum_ab.print();
    std::cout << std::endl;

    Fraction prod_ab = f1.multiply(f2);
    std::cout << "f1 * f2 = ";
    prod_ab.print();
    std::cout << std::endl;

    Fraction div_ab = f1.divide(f2);
    std::cout << "f1 / f2 = ";
    div_ab.print();
    std::cout << std::endl;

    std::cout << "zero: ";
    zero.print();
    std::cout << std::endl;

    std::cout << "whole: ";
    whole.print();
    std::cout << std::endl;

    Fraction copied(f3);
    std::cout << "copy: ";
    copied.print();
    std::cout << std::endl;
}
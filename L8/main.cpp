#include "stack.h"
#include "calculator.h"
#include <iostream>
#include <string>

int main() {
    Calculator calc;

    std::string good_expr = "(2+6)/(7-5)";
    std::cout << good_expr << " is valid? " << (calc.check_expr(good_expr) ? "yes" : "no") << "\n";
    std::cout << "Result: " << calc.eval_expr(good_expr) << "\n";

    std::string bad_expr1 = "(5+7/2";
    std::cout << bad_expr1 << " is valid? " << (calc.check_expr(bad_expr1) ? "yes" : "no") << "\n";

    std::string bad_expr2 = "3+";
    std::cout << bad_expr2 << " is valid? " << (calc.check_expr(bad_expr2) ? "yes" : "no") << "\n";

    return 0;
}
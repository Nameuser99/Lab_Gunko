#include "calculator.h"
#include <iostream>
#include <cstdlib>

bool Calculator::is_number_char(char c) const {
    return (c >= '0' && c <= '9');
}

bool Calculator::is_op(char c) const {
    if (c == '+' || c == '-' || c == '*' || c == '/') {
        return true;
    }
    return false;
}

int Calculator::get_prec(char op) const {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double Calculator::do_op(double a, double b, char op) const {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) {
            std::cout << "Cant divide by zero\n";
            std::exit(1);
        }
        return a / b;
    }
    return 0;
}

bool Calculator::check_expr(const std::string& expr) {
    int i = 0;
    int paren_count = 0;
    bool expect_num = true;
    while (i < static_cast<int>(expr.length())) {
        if (expr[i] == ' ') {
            ++i;
            continue;
        }
        if (expr[i] == '(') {
            ++paren_count;
            expect_num = true;
        } else if (expr[i] == ')') {
            --paren_count;
            if (paren_count < 0 || expect_num) return false;
            expect_num = false;
        } else if (is_number_char(expr[i])) {
            if (!expect_num) return false;
            expect_num = false;
            while (i < static_cast<int>(expr.length()) && is_number_char(expr[i])) ++i;
            --i;
        } else if (is_op(expr[i])) {
            if (expect_num) return false;
            expect_num = true;
        } else {
            return false;
        }
        ++i;
    }
    return paren_count == 0 && !expect_num;
}

double Calculator::eval_expr(const std::string& expr) {
    if (!check_expr(expr)) {
        std::cout << "Bad expression\n";
        std::exit(1);
    }
    Stack nums;
    Stack ops;
    int i = 0;
    while (i < static_cast<int>(expr.length())) {
        if (expr[i] == ' ') {
            ++i;
            continue;
        }
        if (is_number_char(expr[i])) {
            double num = 0;
            while (i < static_cast<int>(expr.length()) && is_number_char(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                ++i;
            }
            nums.push(num);
            --i;
        } else if (expr[i] == '(') {
            ops.push(static_cast<double>('('));
        } else if (expr[i] == ')') {
            while (!ops.empty() && ops.top() != static_cast<double>('(')) {
                double b = nums.pop();
                double a = nums.pop();
                char op = static_cast<char>(ops.pop());
                nums.push(do_op(a, b, op));
            }
            if (!ops.empty()) {
                ops.pop();
            }
        } else if (is_op(expr[i])) {
            while (!ops.empty() && get_prec(static_cast<char>(ops.top())) >= get_prec(expr[i])) {
                double b = nums.pop();
                double a = nums.pop();
                char op = static_cast<char>(ops.pop());
                nums.push(do_op(a, b, op));
            }
            ops.push(static_cast<double>(expr[i]));
        }
        ++i;
    }
    while (!ops.empty()) {
        double b = nums.pop();
        double a = nums.pop();
        char op = static_cast<char>(ops.pop());
        nums.push(do_op(a, b, op));
    }
    return nums.pop();
}
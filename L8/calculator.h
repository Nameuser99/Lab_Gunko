#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "stack.h"
#include <string>

class Calculator {
private:
    bool is_number_char(char c) const;
    bool is_op(char c) const;
    int get_prec(char op) const;
    double do_op(double a, double b, char op) const;

public:
    bool check_expr(const std::string& expr);
    double eval_expr(const std::string& expr);
};

#endif
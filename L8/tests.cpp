#include "stack.h"
#include "calculator.h"
#include <iostream>
#include <string>

int main() {
    Stack s;
    s << 1.0;
    s << 2.0;
    s << 3.0;
    double v;
    s >> v;
    if (v != 3.0) std::cout << "pop fail\n";
    s >> v;
    if (v != 2.0) std::cout << "pop fail\n";
    s >> v;
    if (v != 1.0) std::cout << "pop fail\n";
    if (!s.empty()) std::cout << "empty fail\n";

    Stack s1;
    s1 << 4.0 << 5.0;
    Stack s2 = s1;
    if (!(s1 == s2)) std::cout << "assign fail\n";
    s2 >> v;
    if (v != 5.0) std::cout << "assign pop fail\n";

    Stack s3;
    s3 << 6.0;
    Stack s4;
    s4 << 6.0 << 7.0;
    if (!(s3 < s4)) std::cout << "less fail\n";

    Stack s5;
    s5 << 8.0 << 9.0;
    Stack s6;
    s6 << 8.0 << 9.0;
    if (!(s5 == s6)) std::cout << "equal fail\n";

    Stack s7;
    s7 << 10.0 << 11.0 << 12.0;
    if (s7[0] != 10.0 || s7[1] != 11.0 || s7[2] != 12.0) std::cout << "index fail\n";

    Calculator c;
    if (!c.check_expr("(2+6)/(7-5)")) std::cout << "valid fail\n";
    if (c.check_expr("(5+7/2")) std::cout << "invalid pass fail\n";
    if (c.check_expr("3+")) std::cout << "invalid pass fail\n";

    if (c.eval_expr("(2+6)/(7-5)") != 4.0) std::cout << "calc fail\n";

    std::cout << "Tests done!";
}
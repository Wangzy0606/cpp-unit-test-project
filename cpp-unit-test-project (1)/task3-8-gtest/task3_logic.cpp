// task3_logic.cpp
#include "tasks.h"
#include <sstream>

std::string solveEquation(std::string equation) {
    int equal_pos = equation.find('=');
    std::string left = equation.substr(0, equal_pos);
    std::string right = equation.substr(equal_pos + 1);
    
    // 解析左右两边的表达式
    auto [lx, ln] = parseExpression(left);
    auto [rx, rn] = parseExpression(right);
    
    // 合并同类项
    int x = lx - rx;
    int n = rn - ln;
    
    // 解方程
    if (x == 0 && n == 0) {
        return "Infinite";
    } else if (x == 0) {
        return "NO";
    } else {
        return "x=" + std::to_string(n / x);
    }
}

std::pair<int, int> parseExpression(const std::string& expr) {
    int x = 0;
    int n = 0;
    std::istringstream iss(expr);
    int num;
    char op = '+';
    
    while (iss.peek() != EOF) {
        if (iss.peek() == '+' || iss.peek() == '-') {
            op = iss.get();
        }
        
        if (isdigit(iss.peek())) {
            iss >> num;
            if (op == '-') num = -num;
            n += num;
        } else if (iss.peek() == 'x') {
            iss.get();
            int coef = (op == '+') ? 1 : -1;
            x += coef;
        } else {
            // 处理系数的情况，如2x
            int coef;
            iss >> coef;
            if (op == '-') coef = -coef;
            x += coef;
            iss.get(); // 跳过'x'
        }
    }
    
    return {x, n};
}    
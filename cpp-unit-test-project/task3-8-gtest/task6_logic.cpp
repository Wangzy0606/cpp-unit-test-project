// task6_logic.cpp
#include "task6_logic.h"
#include <string>
#include <stack>

int calculate(std::string s) {
    std::stack<int> stack;
    int num = 0;
    int sign = 1;
    int result = 0;
    
    for (char c : s) {
        if (std::isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (c == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (c == '(') {
            stack.push(result);
            stack.push(sign);
            result = 0;
            sign = 1;
        } else if (c == ')') {
            result += sign * num;
            num = 0;
            
            int prevSign = stack.top();
            stack.pop();
            int prevResult = stack.top();
            stack.pop();
            
            result = prevResult + prevSign * result;
        }
    }
    
    if (num != 0) {
        result += sign * num;
    }
    
    return result;
}    
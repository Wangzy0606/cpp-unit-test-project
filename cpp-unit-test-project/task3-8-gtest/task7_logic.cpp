// task7_logic.cpp
#include "task7_logic.h"
#include <vector>

int findIntegers(int n) {
    // 预处理斐波那契数列
    std::vector<int> fib(32);
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < 32; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    int count = 0;
    int prev_bit = 0;
    
    for (int k = 30; k >= 0; --k) {
        if (n & (1 << k)) {
            count += fib[k];
            if (prev_bit == 1) {
                return count;
            }
            prev_bit = 1;
        } else {
            prev_bit = 0;
        }
    }
    
    return count + 1; // 加上n本身
}    
// task2_logic.cpp
#include "task2_logic.h"
#include <cmath>

bool canReachTarget(int sx, int sy, int fx, int fy, unsigned int t) {
    int dx = std::abs(fx - sx);
    int dy = std::abs(fy - sy);
    
    // 计算最短步数
    int min_steps = std::max(dx, dy);
    
    // 检查是否可以在t步内到达
    if (t < min_steps) return false;
    
    // 检查奇偶性
    return (t % 2) == (min_steps % 2);
}    
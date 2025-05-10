// tasks.h
#ifndef TASKS_H
#define TASKS_H

#include <string>
#include <vector>
#include <utility>
#include <stack>
#include <unordered_set>

// 任务3：解方程
std::string solveEquation(std::string equation);
std::pair<int, int> parseExpression(const std::string& expr);

// 任务4：最小时间差
int findMinDifference(std::vector<std::string>& timePoints);

// 任务5：移动到目标位置
bool canReach(int sx, int sy, int fx, int fy);

// 任务6：计算表达式
int calculate(std::string s);

// 任务7：二进制中不包含连续1的数字计数
int findIntegers(int n);

// 任务8：凸包问题
std::vector<std::vector<int>> outerTrees(std::vector<std::vector<int>>& points);

// 自定义哈希函数用于unordered_set<pair<int, int>>
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2));
    }
};

#endif // TASKS_H    
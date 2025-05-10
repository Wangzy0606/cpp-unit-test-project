// task8_logic.cpp
#include "tasks.h"
#include <algorithm>

// 计算叉积
int cross(const std::vector<int>& O, const std::vector<int>& A, const std::vector<int>& B) {
    return (A[0] - O[0]) * (B[1] - O[1]) - (A[1] - O[1]) * (B[0] - O[0]);
}

std::vector<std::vector<int>> outerTrees(std::vector<std::vector<int>>& points) {
    int n = points.size();
    if (n <= 3) return points;
    
    // 按照x坐标排序，如果x相同则按y坐标排序
    std::sort(points.begin(), points.end(), [](const std::vector<int>& p, const std::vector<int>& q) {
        return p[0] < q[0] || (p[0] == q[0] && p[1] < q[1]);
    });
    
    std::vector<std::vector<int>> hull;
    
    // 构建下凸包
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull[hull.size()-1], points[i]) < 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    
    // 构建上凸包
    int t = hull.size() + 1;
    for (int i = n-2; i >= 0; --i) {
        while (hull.size() >= t && cross(hull[hull.size()-2], hull[hull.size()-1], points[i]) < 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }
    
    // 去重
    std::sort(hull.begin(), hull.end());
    hull.erase(std::unique(hull.begin(), hull.end()), hull.end());
    
    return hull;
}    
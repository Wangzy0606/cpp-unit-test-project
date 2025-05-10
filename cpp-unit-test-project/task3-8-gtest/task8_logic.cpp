// task8_logic.cpp
#include "task8_logic.h"
#include <vector>
#include <algorithm>

using namespace std;

// 计算叉积
int cross(const vector<int>& O, const vector<int>& A, const vector<int>& B) {
    return (A[0] - O[0]) * (B[1] - O[1]) - (A[1] - O[1]) * (B[0] - O[0]);
}

vector<vector<int>> outerTrees(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 3) return points;
    
    // 按照x坐标排序，如果x相同则按y坐标排序
    sort(points.begin(), points.end(), [](const vector<int>& p, const vector<int>& q) {
        return p[0] < q[0] || (p[0] == q[0] && p[1] < q[1]);
    });
    
    vector<vector<int>> hull;
    
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
    sort(hull.begin(), hull.end());
    hull.erase(unique(hull.begin(), hull.end()), hull.end());
    
    return hull;
}    
// task4_logic.cpp
#include "tasks.h"
#include <algorithm>

int findMinDifference(std::vector<std::string>& timePoints) {
    // 将时间转换为分钟
    std::vector<int> minutes;
    for (const auto& time : timePoints) {
        int h = std::stoi(time.substr(0, 2));
        int m = std::stoi(time.substr(3, 2));
        minutes.push_back(h * 60 + m);
    }
    
    // 排序
    std::sort(minutes.begin(), minutes.end());
    
    // 添加第二天的第一个时间点
    minutes.push_back(minutes[0] + 24 * 60);
    
    // 计算最小差值
    int minDiff = INT_MAX;
    for (int i = 1; i < minutes.size(); ++i) {
        minDiff = std::min(minDiff, minutes[i] - minutes[i-1]);
    }
    
    return minDiff;
}    
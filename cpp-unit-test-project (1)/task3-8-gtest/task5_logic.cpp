// task5_logic.cpp
#include "tasks.h"
#include <queue>

bool canReach(int sx, int sy, int fx, int fy) {
    std::queue<std::pair<int, int>> q;
    std::unordered_set<std::pair<int, int>, pair_hash> visited;
    
    q.push({sx, sy});
    visited.insert({sx, sy});
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (x == fx && y == fy) return true;
        
        // 生成所有可能的下一步移动
        std::vector<std::pair<int, int>> nextMoves = {
            {x, y - x},
            {x - y, y},
            {2 * x, y},
            {x, 2 * y}
        };
        
        for (auto [nx, ny] : nextMoves) {
            if (nx > 0 && ny > 0 && visited.find({nx, ny}) == visited.end()) {
                if (nx == fx && ny == fy) return true;
                q.push({nx, ny});
                visited.insert({nx, ny});
            }
        }
    }
    
    return false;
}    
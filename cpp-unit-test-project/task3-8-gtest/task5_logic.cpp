// task5_logic.cpp
#include "task5_logic.h"
#include <utility>
#include <queue>
#include <unordered_set>

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2));
    }
};

bool canReach(int sx, int sy, int fx, int fy) {
    queue<pair<int, int>> q;
    unordered_set<pair<int, int>, pair_hash> visited;
    
    q.push({sx, sy});
    visited.insert({sx, sy});
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (x == fx && y == fy) return true;
        
        // 生成所有可能的下一步移动
        vector<pair<int, int>> nextMoves = {
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
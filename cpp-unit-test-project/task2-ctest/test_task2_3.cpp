// test_task2_3.cpp
#include <cassert>
#include "task2_logic.h"

int main() {
    // 步数不足
    assert(!canReachTarget(0, 0, 3, 3, 2));
    return 0;
}    
// task1_assert_tests.cpp
#include <cassert>
#include <iostream>

// 声明要测试的函数
int findBroomHolder(int n, int time);

void test_findBroomHolder1() {
    assert(findBroomHolder(5, 0) == 1); // 初始位置
}

void test_findBroomHolder2() {
    assert(findBroomHolder(5, 3) == 4); // 正向移动
}

void test_findBroomHolder3() {
    assert(findBroomHolder(5, 7) == 3); // 反向移动
}

int main() {
    std::cout << "Running Task 1 Assert Tests..." << std::endl;
    
    std::cout << "Test 1: ";
    test_findBroomHolder1();
    std::cout << "PASSED" << std::endl;
    
    std::cout << "Test 2: ";
    test_findBroomHolder2();
    std::cout << "PASSED" << std::endl;
    
    std::cout << "Test 3: ";
    test_findBroomHolder3();
    std::cout << "PASSED" << std::endl;
    
    std::cout << "All Task 1 tests passed!" << std::endl;
    return 0;
}    
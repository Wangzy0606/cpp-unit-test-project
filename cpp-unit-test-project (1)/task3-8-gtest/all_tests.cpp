// all_tests.cpp
#include <gtest/gtest.h>
#include "tasks.h"  // 使用合并后的头文件

// 任务3测试
TEST(Task3Test, BasicTest) {
    EXPECT_EQ(solveEquation("x+2x+12=6+x-1"), "x=3");
    EXPECT_EQ(solveEquation("x=x"), "Infinite");
    EXPECT_EQ(solveEquation("2x+3=2x+5"), "NO");
}

// 任务4测试
TEST(Task4Test, BasicTest) {
    std::vector<std::string> times1 = {"23:59", "00:00"};
    EXPECT_EQ(findMinDifference(times1), 1);
    
    std::vector<std::string> times2 = {"00:00", "23:59", "00:00"};
    EXPECT_EQ(findMinDifference(times2), 0);
    
    std::vector<std::string> times3 = {"01:00", "02:00", "03:00"};
    EXPECT_EQ(findMinDifference(times3), 60);
}

// 任务5测试
TEST(Task5Test, BasicTest) {
    EXPECT_TRUE(canReach(1, 1, 3, 5));
    EXPECT_FALSE(canReach(1, 1, 2, 2));
    EXPECT_TRUE(canReach(1, 1, 1, 1));
}

// 任务6测试
TEST(Task6Test, BasicTest) {
    EXPECT_EQ(calculate("1 + 1"), 2);
    EXPECT_EQ(calculate(" 2-1 + 2 "), 3);
    EXPECT_EQ(calculate("(1+(4+5+2)-3)+(6+8)"), 23);
}

// 任务7测试
TEST(Task7Test, BasicTest) {
    EXPECT_EQ(findIntegers(5), 5);
    EXPECT_EQ(findIntegers(1), 2);
    EXPECT_EQ(findIntegers(2), 3);
}

// 任务8测试
TEST(Task8Test, BasicTest) {
    std::vector<std::vector<int>> points = {{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
    std::vector<std::vector<int>> expected = {{1,1},{2,0},{3,3},{2,4},{4,2}};
    EXPECT_EQ(outerTrees(points), expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}    
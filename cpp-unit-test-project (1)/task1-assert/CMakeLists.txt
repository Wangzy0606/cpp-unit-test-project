cmake_minimum_required(VERSION 3.14)
project(Task1Assert)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件
add_executable(task1_assert 
    task1_logic.cpp 
    task1_assert_tests.cpp
)

# 添加测试
add_test(NAME Task1AssertTest COMMAND task1_assert)    
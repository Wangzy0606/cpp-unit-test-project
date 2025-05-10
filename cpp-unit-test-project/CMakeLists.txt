cmake_minimum_required(VERSION 3.14)
project(CppUnitTesting)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 启用测试
enable_testing()

# 添加各个子项目
add_subdirectory(task1-assert)
add_subdirectory(task2-ctest)
add_subdirectory(task3-8-gtest)    
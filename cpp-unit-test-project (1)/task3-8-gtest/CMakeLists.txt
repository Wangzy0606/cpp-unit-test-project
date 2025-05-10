cmake_minimum_required(VERSION 3.14)
project(Task38GoogleTest)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找或下载Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# 对于Windows：防止覆盖父项目的编译器/链接器设置
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 添加各个任务的逻辑库
add_library(task3_logic STATIC
    task3_logic.cpp
)

add_library(task4_logic STATIC
    task4_logic.cpp
)

add_library(task5_logic STATIC
    task5_logic.cpp
)

add_library(task6_logic STATIC
    task6_logic.cpp
)

add_library(task7_logic STATIC
    task7_logic.cpp
)

add_library(task8_logic STATIC
    task8_logic.cpp
)

# 添加测试可执行文件
add_executable(all_tests
    all_tests.cpp
)

# 链接Google Test和各个任务的逻辑库
target_link_libraries(all_tests
    PRIVATE
    gtest_main
    task3_logic
    task4_logic
    task5_logic
    task6_logic
    task7_logic
    task8_logic
)

# 添加测试
include(GoogleTest)
gtest_discover_tests(all_tests)    
cmake_minimum_required(VERSION 3.14)
project(Task2CTest)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加任务2的逻辑库
add_library(task2_logic STATIC
    task2_logic.cpp
)

# 添加各个测试文件
add_executable(test_task2_1 test_task2_1.cpp)
add_executable(test_task2_2 test_task2_2.cpp)
add_executable(test_task2_3 test_task2_3.cpp)

# 链接库
target_link_libraries(test_task2_1 PRIVATE task2_logic)
target_link_libraries(test_task2_2 PRIVATE task2_logic)
target_link_libraries(test_task2_3 PRIVATE task2_logic)

# 添加测试
add_test(NAME TestTask2_1 COMMAND test_task2_1)
add_test(NAME TestTask2_2 COMMAND test_task2_2)
add_test(NAME TestTask2_3 COMMAND test_task2_3)    
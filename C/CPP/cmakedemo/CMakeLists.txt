cmake_minimum_required(VERSION 3.10)

# set the project name 工程名
project(TestDemo)

# 设置编译模式
set(CMAKE_BUILD_TYPE Release)

# 设置可执行文件与链接库保存的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置头文件目录
include_directories(
${PROJECT_SOURCE_DIR}/include
)

# 生成动态链接库 SHARED
add_library(dymc_lib SHARED ${PROJECT_SOURCE_DIR}/include/so_test.h
                            ${PROJECT_SOURCE_DIR}/src/test_a.c 
                            ${PROJECT_SOURCE_DIR}/src/test_b.c 
                            ${PROJECT_SOURCE_DIR}/src/test_c.c)
    
# 添加下面两行调用 链接库生成可执行文件
# ADD_EXECUTABLE(hello_dymc src/test_main.c)
# TARGET_LINK_LIBRARIES(hello_dymc dymc_lib)

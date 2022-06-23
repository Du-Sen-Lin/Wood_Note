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
${PROJECT_SOURCE_DIR}/inc
)

# 链接库路径
link_directories(${LIBRARY_OUTPUT_PATH})
# 链接库，dymc_lib 为库名
link_libraries(dymc_lib)

# 生成目标文件
add_executable(TestDemo src/test_main.c)

# 链接库文件
TARGET_LINK_LIBRARIES(TestDemo dymc_lib)

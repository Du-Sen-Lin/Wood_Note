cmake_minimum_required(VERSION 3.10)

# set the project name 工程名
project(clearn)

# 设置编译模式
set(CMAKE_BUILD_TYPE Release)

# 设置可执行文件与链接库保存的路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置头文件目录
include_directories(
${PROJECT_SOURCE_DIR}/include
)
                            
# add the executable 添加编译文件
ADD_EXECUTABLE(clearn src/00_base.c)

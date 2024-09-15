cmake_minimum_required(VERSION 3.10)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 生成 compile_commands.json 用于 clangd 代码补全
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
# 设置为发行模式
# set(CMAKE_BUILD_TYPE "Release")
# 设置为调试模式
set(CMAKE_BUILD_TYPE "Debug")

# 源代码文件
#设置主程序位置
#set (MAIN_SRC_LIST
# "${PROJECT_SOURCE_DIR}/src/main.cpp")

#设置源文件文件夹
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)
# 添加头文件
include_directories(
        "${PROJECT_SOURCE_DIR}/include"
)

# 主程序
add_executable(${PROJECT_NAME} ${SRC_LIST})
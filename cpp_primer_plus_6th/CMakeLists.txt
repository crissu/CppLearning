cmake_minimum_required(VERSION 3.16)
project(libuv_test)

# 设置 C/C++标准
set(CMAKE_C_STANDARD 99)

# 指定引用的外部库的搜索路径
link_directories(
    usr/local/lib
    )

# 头文件路径
include_directories(
    usr/local/include
    )

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置输出名, 方便修改
set(EXECUTABLE_FILE_NAME 3.1)

# 生成可执行的文件
add_executable(${EXECUTABLE_FILE_NAME} ./src/${EXECUTABLE_FILE_NAME}.cpp)

# 打印参数
message("\n---打印参数---\n")
message("EXECUTABLE_FILE_NAME:\t" ${EXECUTABLE_FILE_NAME})
message("\n---end---\n")




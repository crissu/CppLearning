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
set(EXECUTABLE_FILE_NAME tty-gravity)

# 设置libcurl 库的位置
find_package(CURL REQUIRED)
if (CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    set(LIB_LIST ${LIB_LIST} ${CURL_LIBRARIES})
endif (CURL_FOUND)

# 生成可执行的文件
add_executable(${EXECUTABLE_FILE_NAME} ./src/${EXECUTABLE_FILE_NAME}.cpp)

# 打印参数
message("hello-----\n")
message(${CURL_LIBRARIES})
message(${LIB_LIST})
message(${CURL_INCLUDE_DIRS})
message(${EXECUTABLE_OUTPUT_PATH})
message(${EXECUTABLE_FILE_NAME})

message("hello-----\n")
# 链接 ${PROJECT_NAME}
target_link_libraries (${EXECUTABLE_FILE_NAME} -luv ${LIB_LIST})   #libuv.a




cmake_minimum_required(VERSION 3.22)#规定cmake的最低版本要求
project(cmake_test)#项目的名称，不一定和你的文件夹名称一样
set(CMAKE_CXX_COMPILE "gcc")#设置c++编译器
# set(CMAKE_CXX_FLAGS "-lpthread")#设置编译选项，lpthread是使用了pthread

# include_directories(${PROJECT_SOURCE_DIR}/include)#添加头文件的搜索路径
file(GLOB_RECURSE SrcFiles ./src/*.cpp) # 设置需要编译的代码存放路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})#设置可执行文件输出路径
add_executable(cmake_test ${SrcFiles})#设置可执行文件的名称，make之后bin目录下出现test  
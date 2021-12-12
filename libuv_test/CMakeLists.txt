cmake_minimum_required(VERSION 3.16)
project(libuv_test)

# 设置 C/C++标准
set(CMAKE_C_STANDARD 99)

# 指定引用的外部库的搜索路径
link_directories(usr/local/lib)

# 头文件路径
include_directories(usr/local/include/libuv/include)

# 将源文件列表写在变量SrcFiles中
aux_source_directory(./src SrcFiles)

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 设置输出名, 方便修改
set(EXECUTABLE_FILE_NAME progress)
# idle-basic 空转
# uvcat  模拟 cat 读取
# uvtee  流式读取输出
# onchange  监控文件变化
# tcp-echo-server  tcp 服务端
# tcp-echo-client  tcp 客户端
# udp-dhcp  udp 从DCHP服务器获取ip的例子
# dns  异步的 DNS 查询
# interfaces  获得系统的网络接口信息
# thread-create  创建线程
# ocks  读写锁 多线程 demo
# once  once 多线程只执行一次 demo
# queue-work  使得一个应用程序能够在不同的线程运行任务，当任务完成后，回调函数将会被触发
# queue-cancel  当用户想要终止程序的时候，uv_cancel()可以用来清理任务队列中的等待执行的任务
# progress 进程间通信  一个下载管理程序向用户展示各个下载线程的进度


# 生成可执行的文件
add_executable(${EXECUTABLE_FILE_NAME} ./src/${EXECUTABLE_FILE_NAME}.cpp)

# 链接 ${PROJECT_NAME}
target_link_libraries (${EXECUTABLE_FILE_NAME} -luv )   #libuv.a




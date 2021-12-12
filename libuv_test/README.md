# libuv_test
## 说明  
libuv 学习代码  

## 文件说明
- build 编译目录  
- res 素材
- src 源代码
- bin 可执行文件保存

## src 代码
- idle-basic 空转
- uvcat  模拟 cat 读取
- uvtee  流式读取输出
- onchange  监控文件变化
- tcp-echo-server  tcp 服务端
- tcp-echo-client  tcp 客户端
- udp-dhcp  udp 从DCHP服务器获取ip的例子
- dns  异步的 DNS 查询
- interfaces  获得系统的网络接口信息
- thread-create  创建线程
- ocks  读写锁 多线程 demo
- once  once 多线程只执行一次 demo
- queue-work  使得一个应用程序能够在不同的线程运行任务，当任务完成后，回调函数将会被触发
- queue-cancel  当用户想要终止程序的时候，uv_cancel()可以用来清理任务队列中的等待执行的任务
- progress 进程间通信  一个下载管理程序向用户展示各个下载线程的进度
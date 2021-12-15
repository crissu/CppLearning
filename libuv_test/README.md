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
- progress  进程间通信  一个下载管理程序向用户展示各个下载线程的进度
- spawning  创建一个子进程 你想要开始一个进程，然后知道它什么时候终止。需要使用uv_spawn完成任务  
- detach  启动守护进程(daemon)，或者是使得子进程从父进程中独立出来，这样父进程的退出就不会影响到它 
- signal  
  Sending signals to processes 一个使用了多个event-loop的服务器程序，只要简单地给每一个进程添加信号SIGINT监视器，就可以保证程序在中断退出前，数据能够安全地保存。  
- proc-streams  
  一个正常的新产生的进程都有自己的一套文件描述符映射表，例如0，1，2分别对应stdin，stdout和stderr。有时候父进程想要将自己的文件描述符映射表分享给子进程。例如，你的程序启动了一个子命令，并且把所有的错误信息输出到log文件中，但是不能使用stdout。因此，你想要使得你的子进程和父进程一样，拥有stderr。在这种情形下，libuv提供了继承文件描述符的功能。  
- cgi  
  cgi的stdout被绑定到socket上，所以无论tick脚本程序打印什么，都会发送到client端。  
- pipe-echo-server  
  本地socket具有确定的名称，而且是以文件系统上的位置来标示的（例如，unix中socket是文件的一种存在形式），那么它就可以用来在不相关的进程间完成通信任务  
- uvstop  
  高级事件循环，uv_stop()用来终止event loop。loop会停止的最早时间点是在下次循环的时候，或者稍晚些的时候。这也就意味着在本次循环中已经准备被处理的事件，依然会被处理，uv_stop不会起到作用。当uv_stop被调用，在当前的循环中，loop不会被IO操作阻塞。
- ref-timer  
  定时器
- idle-compute  
  空转的回调函数会在每一次的event-loop循环激发一次。空转的回调函数可以用来执行一些优先级较低的活动。比如，你可以向开发者发送应用程序的每日性能表现情况，以便于分析，或者是使用用户应用cpu时间来做SETI运算:)。空转程序还可以用于GUI应用。比如你在使用event-loop来下载文件，如果tcp连接未中断而且当前并没有其他的事件，则你的event-loop会阻塞，这也就意味着你的下载进度条会停滞，用户会面对一个无响应的程序。  
- uvwget  
  简单地实现一个下载管理程序，它会通过libcurl来下载文件。我们不会直接控制libcurl，而是使用libuv的event-loop，通过非阻塞的异步的多重接口来处理下载，与此同时，libuv会监控IO的就绪状态。  
- plugin  
  实现你自己的插件／扩展／模块系统，它们可以被nodejs通过require()调用。只要你的库输出的是正确的符号，用起来还是很简单的。在载入第三方库的时候，要注意错误和安全检查，否则你的程序就会表现出不可预测的行为。  
- tty
  把白字打印到红色背景上的例子  
- tty-gravity
  实现了一个动画的效果, Hello TTY 会在屏幕上移动，最后停下来  
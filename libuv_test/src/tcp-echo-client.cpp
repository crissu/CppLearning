/*
 * @Author: your name
 * @Date: 2021-12-11 13:22:40
 * @LastEditTime: 2021-12-11 14:17:53
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: /cpp_projects/CppLearning/libuv_test/src/tcp-echo-client.cpp
 */
#include <iostream>
#include <uv.h>
/*
    这个程序还有问题
*/

using namespace std;

#define DEFAULT_PORT 7000

uv_loop_t *loop;
struct sockaddr_in dest;

void on_connect(uv_connect_t *req, int status)
{
    if (status < 0)
    {
        fprintf(stderr, "Client New connection error %s\n", uv_strerror(status));
        // error!
        return;
    }
    cout << "连接成功"<<endl;
    fprintf(stderr, "Client Status %d: ", status);
}

int main()
{
    loop = uv_default_loop();
    uv_tcp_t *socket = (uv_tcp_t *)malloc(sizeof(uv_tcp_t));
    uv_tcp_init(loop, socket);

    uv_connect_t *connect = (uv_connect_t *)malloc(sizeof(uv_connect_t));

    uv_ip4_addr("127.0.0.1", DEFAULT_PORT, &dest);

    cout << "Client 开始连接"<<endl;
    uv_tcp_connect(connect, socket, (const struct sockaddr *)&dest, on_connect);

    return 0;
}

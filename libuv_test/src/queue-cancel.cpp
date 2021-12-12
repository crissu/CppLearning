#include <stdio.h>
#include <uv.h>
#include <stdlib.h>
#include <unistd.h>

uv_loop_t *loop;
#define FIB_UNTIL 25
uv_work_t fib_reqs[FIB_UNTIL];

long fib_(long n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return fib_(n - 1) + fib_(n - 2);
    }
}

void fib(uv_work_t *req)
{
    int n = *(int *)req->data;
    if (random() % 2)
    {
        sleep(1);
    }
    else
    {
        sleep(3);
    }
    long fib = fib_(n);
    fprintf(stderr, "%dth fibonacci is %lu\n", n, fib);
}

void after_fib(uv_work_t *req, int status)
{
    if (status == UV_ECANCELED)
    {
        fprintf(stderr, "Calculation of %d cancelled.\n", *(int *)req->data);
    }
}

void signal_handler(uv_signal_t *req, int signum)
{
    printf("Signal received");
    int i;
    for (i = 0; i < FIB_UNTIL; i++)
    {
        uv_cancel((uv_req_t *)&fib_reqs[i]);
    }
    uv_signal_stop(req);
}

int main()
{
    loop = uv_default_loop();

    int data[FIB_UNTIL];

    int i;
    for (i = 0; i < FIB_UNTIL; i++)
    {
        data[i] = i;
        fib_reqs[i].data = (void *)&data[i];
        uv_queue_work(loop, &fib_reqs[i], fib, after_fib);
    }

    uv_signal_t signal;
    uv_signal_init(loop, &signal);
    uv_signal_start(&signal, signal_handler, SIGINT);

    return uv_run(loop, UV_RUN_DEFAULT);
}

#include <stdio.h>
#include <uv.h>

uv_loop_t *loop;
uv_timer_t gc_req;
uv_timer_t fake_job_req;

void gc(uv_timer_t *handle)
{
    fprintf(stderr, "Freeing unused objects\n");
}

void fake_job(uv_timer_t *handle)
{
    fprintf(stdout, "Fake job done\n");
}

int main()
{
    loop = uv_default_loop();

    uv_timer_init(loop, &gc_req);
    uv_unref((uv_handle_t *)&gc_req); // gc_req是定时间隔触发，uv_unref可以在程序结束的时候关闭定时器

    uv_timer_start(&gc_req, gc, 0, 2000); // 定时每2s触发一次

    uv_timer_init(loop, &fake_job_req);
    uv_timer_start(&fake_job_req, fake_job, 9000, 0); // 定时9s的时候触发一次

    return uv_run(loop, UV_RUN_DEFAULT);
}

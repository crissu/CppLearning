#include <stdio.h>
#include <uv.h>

static uv_once_t once_only = UV_ONCE_INIT;

int i = 0;

void increment()
{
    i++;
}

void thread1(void *arg)
{
    /* ... work */
    uv_once(&once_only, increment);
}

void thread2(void *arg)
{
    /* ... work */
    uv_once(&once_only, increment);
}

int main()
{
    uv_thread_t hare_id;
    uv_thread_t tortoise_id;
    uv_thread_create(&hare_id, thread1, NULL);
    uv_thread_create(&tortoise_id, thread2, NULL);

    uv_thread_join(&hare_id);
    uv_thread_join(&tortoise_id);

    if (i == 1)
    {
        fprintf(stderr, "i == %d\n", i);
    }

    return 0;
}

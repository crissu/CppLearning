// main.cpp
#include <iostream>
#include "./queue/queue.h"
#include <cstdlib>

int main(int argc, char **argv)
{
    Queue queue(10);

    for (int i = 0; i < 5; i++)
    {
        Item it;
        it.set(i + 1);
        if (!queue.enqueue(it))
        {
            std::cout << "enqueue failed, it.when:" << it.when() << std::endl;
        }
        std::cout << "enqueue succ, it.when:" << it.when() << std::endl;
    }
    queue.show();
    for (int i = 0; i < 5; i++)
    {
        Item it;
        if (!queue.dequeue(it))
        {
            std::cout << "dequeue failed, it.when:" << it.when() << std::endl;
        }
        std::cout << "dequeue succ, it.when:" << it.when() << std::endl;
    }
    queue.show();
    return 0;
}
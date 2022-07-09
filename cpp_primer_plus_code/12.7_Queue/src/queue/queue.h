// queue.h -- interface for a queue
#ifndef QUEUE_H_
#define QUEUE_H_
// This queue will contain Customer items
class Customer
{
private:
    long arrive;
    int processTime;

public:
    Customer() { arrive = processTime = 0; }
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processTime; }
};

typedef Customer Item;

class Queue
{
private:
    // class scope definitions
    struct Node
    {
        Item item;
        struct Node *next;
    };
    enum
    {
        Q_SIZE = 10
    };
    // private class members
    Node *front;
    Node *rear;
    int items;
    const int qsize;
    // 私有构建方法，防止类被复制
    Queue(const Queue &q) : qsize(0) {}
    Queue &operator=(const Queue &q) { return *this; }

public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    int queueCount() const;
    void show() const;
    bool enqueue(const Item &Item);
    bool dequeue(Item &Item);
};

#endif
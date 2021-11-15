/******************
 * C++多态的应用
 * 
 * 队列和堆栈
 * ***************/

#include <iostream>
#include <string>

using namespace std;

class list
{
public:
    list *head;
    list *tail;
    list *next;
    int num;                              //当前节点的值
    list() { head = tail = next = NULL; } // 构造函数
    virtual void store(int a) = 0;        //增加节点
    virtual int retrive() = 0;            // 删除节点
};

// 队列
class queue : public list
{
public:
    virtual void store(int i)
    {
        list *item = new queue;
        if (!item)
        {
            cout << "内存分配失败" << endl;
            exit(1);
        }
        item->num = i;

        // 链表末尾插入
        if (tail)
        {
            tail->next = item;
        }
        tail = item;
        item->next = NULL;
        if (!head)
        {
            head = tail;
        }
    }

    int retrive()
    {
        int i;
        list *p;

        if (!head)
        {
            cout << "链表已为空" << endl;
            return 0;
        }
        i = head->num;
        p = head;
        head = head->next;
        delete p;
        return i;
    }
};

class stack : public list
{
public:
    virtual void store(int i)
    {
        list *item = new stack;
        if (!item)
        {
            cout << "内存分配失败" << endl;
            exit(1);
        }
        item->num = i;

        if (head)
        {
            item->next = head;
        }
        head = item;
        if (!tail)
        {
            tail = head;
        }
    }

    int retrive()
    {
        int i;
        list *p;

        if (!head)
        {
            cout << "链表已经为空" << endl;
            return 0;
        }

        // 从链表头部删除
        i = head->num;
        p = head;
        head = head->next;
        delete p;
        return i;
    }
};

int main()
{
    list *p;

    // 队列
    queue q;
    p = &q;
    p->store(123), p->store(234), p->store(345);
    cout << "队列:" << endl;
    cout << p->retrive() << "  ";
    cout << p->retrive() << "  ";
    cout << p->retrive() << endl;

    // 栈
    stack s;
    p = &s;
    p->store(123), p->store(234), p->store(345);
    cout << "栈:" << endl;
    cout << p->retrive() << "  ";
    cout << p->retrive() << "  ";
    cout << p->retrive() << endl;

    return 0;
}

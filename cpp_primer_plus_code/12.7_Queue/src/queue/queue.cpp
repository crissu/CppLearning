#include "queue.h"
#include <cstdlib>
#include<iostream>

void Customer::set(long when)
{
    arrive = when;
    processTime = std::rand() % 3 + 1;
}

Queue::Queue(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

Queue::~Queue()
{
    Node *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool Queue::isEmpty() const {
    return items==0;
}

bool Queue::isFull() const{
    return items == qsize;
}

bool Queue::enqueue(const Item & item) {
    if (isFull()){
        return false;
    }
    Node * add = new(Node); // 如果没有内存了，会爆错 std::bad_alloc exception
    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr){
        front = add;
    }else{
        rear->next = add;
    }
    rear = add;
    return true;
}

bool Queue::dequeue(Item & item){
    if (front == nullptr){
        return false;
    }
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0){
        rear = nullptr;
    }
    return true;
}

void Queue::show() const{
    Node * tmp = front;
    std::cout<<"Queue info:"<<std::endl;
    std::cout<<"cur items:"<<items<<std::endl;
    std::cout<<"cur qsize:"<<qsize<<std::endl;
    while (tmp != nullptr)
    {
        std::cout<<"cur node.when:" << tmp->item.when()<<std::endl;
        tmp = tmp->next;
    }
}
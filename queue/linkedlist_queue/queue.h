#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <vector>
#include <stdexcept>

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int _val = 0)
    {
        val = _val;
        next = nullptr;
    }
};

class LinkedListQueue
{
private:
    ListNode *front, *rear;
    int queSize;

public:
    LinkedListQueue();
    ~LinkedListQueue();
    int size();
    bool isEmpty();
    void push(int num);
    int pop();
    int peek();//访问队首元素
    std::vector<int> toVector();
};


void freeMemoryLinkedList(ListNode *&head);
#endif // QUEUE_H
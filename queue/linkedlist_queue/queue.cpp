#include "queue.h"
using namespace std;

LinkedListQueue::LinkedListQueue()
{
    front = nullptr;
    rear = nullptr;
    queSize = 0;
}


LinkedListQueue::~LinkedListQueue()
{
    freeMemoryLinkedList(front);
}


void freeMemoryLinkedList(ListNode *&head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        ListNode *nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr; // 避免悬空指针
}



int LinkedListQueue::size()
{
    return queSize;
}

bool LinkedListQueue::isEmpty()
{
    return queSize == 0;
}


void LinkedListQueue::push(int num)
{
    ListNode *node = new ListNode(num);
    if(front == nullptr)
    {
        front = node;
        rear = node;
    }
    else{
        rear -> next = node;
        rear = node;
    }
    queSize++;
}


int LinkedListQueue::pop()
{
    int num = peek();
    ListNode *tmp = front;
    front = front -> next;
    delete tmp;
    queSize--;
    return num;
}


int LinkedListQueue::peek()
{
    if(size() == 0)
        throw out_of_range("空队列");
    return front -> val;
}


vector<int> LinkedListQueue::toVector()
{
    ListNode *node = front;
    vector<int> res(size());
    for(int i = 0;i < res.size();i++)
    {
        res[i] = node -> val;
        node = node -> next;
    }
    return res;
}
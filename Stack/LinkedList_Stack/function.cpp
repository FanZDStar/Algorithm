#include "LinkedList_Stack.h"
using namespace std;

// 构造函数
LinkedListStack::LinkedListStack()
{
    stackTop = nullptr;
    stkSize = 0;
}

// 析构函数
LinkedListStack::~LinkedListStack()
{
    freeMemoryLinkedList(stackTop);
}

// 释放函数
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

int LinkedListStack::size()
{
    return stkSize;
}

bool LinkedListStack::isEmpty()
{
    return size() == 0;
}

void LinkedListStack::push(int num)
{
    ListNode *node = new ListNode(num);
    node->next = stackTop;
    stackTop = node;
    stkSize++;
}

int LinkedListStack::pop()
{
    int num = top();
    ListNode *tmp = stackTop;
    stackTop = stackTop->next;
    delete tmp;
    stkSize--;
    return num;
}

int LinkedListStack::top()
{
    if (isEmpty())
    {
        throw out_of_range("栈为空");
    }
    else
    {
        return stackTop->val;
    }
}

// 将List转为Array并输出
vector<int> LinkedListStack::toVector()
{
    ListNode *node = stackTop;
    vector<int> res(size());
    for (int i = res.size() - 1; i >= 0; i--)
    {
        res[i] = node->val;
        node = node->next;
    }
    return res;
}
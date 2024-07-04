#ifndef LINKEDLIST_STACK_H
#define LINKEDLIST_STACK_H

#include <iostream>
#include <vector>
#include <stdexcept>

/* 链表节点结构体 */
struct ListNode
{
    int val;                                   // 节点值
    ListNode *next;                            // 指向下一节点的指针
    ListNode(int x) : val(x), next(nullptr) {} // 构造函数
};
class LinkedListStack
{
private:
    ListNode *stackTop; // 将头节点作为栈顶
    int stkSize;        // 栈的长度

public:
    LinkedListStack();

    ~LinkedListStack();

    /* 获取栈的长度 */
    int size();

    /* 判断栈是否为空 */
    bool isEmpty();

    /* 入栈 */
    void push(int num);

    /* 出栈 */
    int pop();

    /* 访问栈顶元素 */
    int top();

    /* 将 List 转化为 Array 并返回 */
    std::vector<int> toVector();
};
void freeMemoryLinkedList(ListNode*& head);

#endif // LINKEDLIST_STACK.H
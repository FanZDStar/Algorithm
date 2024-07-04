#include <iostream>
#include <cstdlib>

using namespace std;

// 定义节点

struct ListNode
{
    int val;                                   // 节点值
    ListNode *next;                            // 指向下一节点的指针
    ListNode(int x) : val(x), next(nullptr) {} // 构造函数
};

// 增
void Insert(ListNode *n0, ListNode *P)
{
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

// 删
// 删除链表的节点 n0 之后的首个节点 
void remove(ListNode *n0) {
    if (n0->next == nullptr)
        return;
    // n0 -> P -> n1
    ListNode *P = n0->next;
    ListNode *n1 = P->next;
    n0->next = n1;
    // 释放内存
    delete P;
}

// 查
int find(ListNode *head, int target)
{
    int index = 0;
    while (head != nullptr)
    {
        if(head->val == target)
            return index;
        head = head -> next;
        index++;
    }
    return -1;
}


// 
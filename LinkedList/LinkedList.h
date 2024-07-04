#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>

/* 链表节点结构体 */
struct ListNode {
    int val;         // 节点值
    ListNode *next;  // 指向下一节点的指针
    ListNode(int x) : val(x), next(nullptr) {}  // 构造函数
};
void insert(ListNode *n0, ListNode *P);
void remove(ListNode *n0);
ListNode *access(ListNode *head, int index);
int find(ListNode *head, int target);


#endif // LINKLIST_H

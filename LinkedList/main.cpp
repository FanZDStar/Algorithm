#include "LinkedList.h"
#include <iostream>

// 打印链表内容
void printList(ListNode *head) {
    ListNode *current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // 创建一个链表：1 -> 2 -> 3
    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    
    head->next = node2;
    node2->next = node3;

    std::cout << "初始链表: ";
    printList(head);

    // 测试插入操作
    ListNode *newNode = new ListNode(4);
    insert(node2, newNode);  // 在节点2之后插入节点4
    std::cout << "在2之后插入4: ";
    printList(head);

    // 测试删除操作
    remove(node2);  // 删除节点2之后的首个节点
    std::cout << "删除2之后的节点: ";
    printList(head);

    // 测试查找操作
    int target = 3;
    int index = find(head, target);
    if (index != -1) {
        std::cout << "找到值为 " << target << " 的节点，索引为: " << index << std::endl;
    } else {
        std::cout << "未找到值为 " << target << " 的节点" << std::endl;
    }

    // 测试访问操作
    int accessIndex = 1;
    ListNode *accessedNode = access(head, accessIndex);
    if (accessedNode != nullptr) {
        std::cout << "访问索引为 " << accessIndex << " 的节点，值为: " << accessedNode->val << std::endl;
    } else {
        std::cout << "访问索引为 " << accessIndex << " 的节点失败" << std::endl;
    }

    // 释放内存
    while (head != nullptr) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

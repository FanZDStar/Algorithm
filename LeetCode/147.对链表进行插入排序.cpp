/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next)
            return head;
        ListNode * pre = new ListNode(-1);
        pre -> next = head;

        ListNode * tail = head;
        ListNode * node = head->next; 

        while(node){
            if(node->val < tail->val){
                ListNode * cur = pre;
                while(cur->next && node->val >  cur->next->val){
                    cur = cur->next;
                }
                tail->next = node->next;
                node->next = cur->next;
                cur->next =  node;
                node=tail->next;

            }else{
                tail = tail->next;
                node = tail->next;
            }
        }
        return pre->next;
    }
};

// @lc code=end


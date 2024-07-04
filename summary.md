[TOC]



## 一.快慢指针法

#### 快慢指针寻找链表中间节点

初始时，快指针fast和慢指针slow均指向链表的左端点。我们将快指针fast向右移动两次的同时，将慢指针slow向右移动一次，直到快指针到达边界（即快指针到达右端点或快指针的下一个节点是右端点）。此时，慢指针slow对应的元素就是中位数。

快慢指针同时从头节点开始，快指针每次走两步，慢指针每次走一步。当快指针走到链表末尾的时候，慢指针正好到达链表的中间结点。（注意特况特判，即链表中有0或1个结点时）



```c++
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
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr){return nullptr;}
        if(head->next==nullptr) return head;
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```

#### 判断链表中是否有环

设想一个情景：两个人在赛跑，A速度快，B速度慢，若是存在环(勺状图)，A和B总是会相遇的，相遇时A所经过的路径的长度要比B多若干个环的长度。

在本题中，快慢指针的思想即是如此，快指针每次走两步，慢指针每次走一步，它们同时从头节点出发。如果二者相遇，则说明存在环；如果快指针到达链表尾NULL，则说明不存在环。

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow==fast) return true;
        }
        return false;
    }
};
```

#### 判断链表中是否有环并找到环的起点

如果链表中有环，那么说明快慢指针会在环中的某位置相遇。此时，应让二者分别从head和相遇节点同时开始每次走一步。当它们再次相遇时，二者所在的结点便是环的入口结点。

![img](https://img-blog.csdnimg.cn/direct/8a13be6406fc4436a7ff13b9df291ce3.png)

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while(index1 != index2){
                    index1=index1->next;
                    index2=index2->next;
                }
                return index2;
            }
        }
        return NULL;
    }
};
```

#### 重排链表

##### 解题思路

1. 快慢指针找到中间结点

2. 后半条链反转链表

3. 合并两条链表

	```c++
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
	    ListNode* middleNode(ListNode* head){
	        if(head==nullptr) return nullptr;
	        if(head->next == nullptr) return head;
	        ListNode* fast = head->next->next;
	        ListNode* slow = head->next;
	        while(fast!=nullptr && fast->next!=nullptr){
	            slow = slow->next;
	            fast = fast->next->next;
	        }
	        return slow;
	    }
	 
	    ListNode* reverseList(ListNode* head){
	        if(head==nullptr) return nullptr;
	        if(head->next == nullptr) return head;
	        ListNode* pre = nullptr;
	        ListNode* cur = head;
	        while(cur!=nullptr){
	            ListNode* tmp = cur->next;
	            cur->next = pre;
	            pre = cur;
	            cur = tmp;
	        }
	        return pre;
	    }
	 
	    void mergeList(ListNode* head1,ListNode* head2){
	        ListNode* tmp1,* tmp2;
	        while(head1!=nullptr && head2!=nullptr){
	            tmp1 = head1->next;
	            tmp2 = head2->next;
	 
	            head1->next = head2;
	            head1 = tmp1;
	 
	            head2->next = head1;
	            head2 = tmp2;
	        }
	    }
	 
	 
	    void reorderList(ListNode* head) {
	        if(head==nullptr) return;
	        ListNode* mid = middleNode(head);
	        ListNode* h1 = head;
	        ListNode* h2 = mid->next;
	        mid->next = nullptr;
	        h2 = reverseList(h2);
	        mergeList(h1,h2);
	    }
	};
	```

	

#### 删除链表中的倒数第N个结点

解题思路
总体目标
快指针先走几步，然后快慢指针一起走，最终快指针指向null的时候，慢指针正好指向要删除结点的前一个结点，借慢指针来实现倒数第N个结点的删除。

实现方法
创建一个虚拟头结点，并使其指向当前链表的头结点。

slow指针从虚拟头结点dummyhead出发，fast指针从头结点head出发。（如果都从head出发，则实现的是slow指针最后指向要删除的结点。正如前面所说，为了便于删除，要使得慢指针正好指向要删除结点的前一个结点。因此，slow从dummyhead出发，fast从head出发）

开始时，fast指针先行N步，slow指针原地待命。

然后，fast指针和slow指针同时向后迈步，每次迈一步，直至fast指针指向NULL。此时，slow指针指向的就正好是要删除结点的前一个结点。在此进行删除工作即可。

注意
本题中确保了N不会大于链表长度，因此也就不需要考虑要删除的结点不存在的问题。

否则，应将N与链表长度作比较，确定倒数第N个链表结点存在后，再进行上述的删除操作。

```c++
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyhead = new ListNode(0, head);
        ListNode* fast = head;
        ListNode* slow = dummyhead;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }
        while (fast!=nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* d = slow->next;
        slow->next = slow->next->next;
        ListNode* ans = dummyhead->next;
        delete d;
        delete dummyhead;
        return ans;
    }
};
```



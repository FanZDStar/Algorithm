##   LeetCode

[TOC]



### T206	翻转链表

给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表。

![image-20240625001727027](C:/Users/hp/AppData/Roaming/Typora/typora-user-images/image-20240625001727027.png)

```c++


class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
}

```

### T1	两数之和

给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** *`target`* 的那 **两个** 整数，并返回它们的数组下标。你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。你可以按任意顺序返回答案。

 **示例 1：**

```
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**示例 2：**

```
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

**示例 3：**

```
输入：nums = [3,3], target = 6
输出：[0,1]
```

#### Code

####  哈希表

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         std::unordered_map<int, int> num_map;
         for(int i = 0;i<nums.size();i++)
         {
            int complement = target - nums[i];
            if(num_map.find(complement)!=num_map.end()){
                return {i,num_map[complement]};
            }
            num_map[nums[i]]=i;
         } 
        return {};
    }
    

};
```


注意到方法一的时间复杂度较高的原因是寻找 target - x 的时间复杂度过高。因此，我们需要一种更优秀的方法，能够快速寻找数组中是否存在目标元素。如果存在，我们需要找出它的索引。

使用哈希表，可以将寻找 target - x 的时间复杂度降低到从 O(N)降低到 O(1)。

这样我们创建一个哈希表，对于每一个 x，我们首先查询哈希表中是否存在 target - x，然后将 x 插入到哈希表中，即可保证不会让 x 和自己匹配。

### T2	两数相加

#### 题目：

![image-20240625171208650](C:/Users/hp/AppData/Roaming/Typora/typora-user-images/image-20240625171208650.png)

#### 题解：



![image-20240625171604911](C:/Users/hp/AppData/Roaming/Typora/typora-user-images/image-20240625171604911.png)

#### Code

```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while(l1||l2)
        {
            
            int num1 = l1 ? l1->val: 0;
            int num2 = l2 ? l2->val: 0; 
            int sum = num1 + num2 + carry;
            if(head == nullptr)
            {
                head = tail = new ListNode(sum % 10);  
            }
            else
            {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum/10;
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        if(carry > 0){
            tail->next = new ListNode(carry);
        }
        return head;
    }
};
```

### T3	无重复字符的最长子串

给定一个字符串 `s` ，请你找出其中不含有重复字符的 最长子串的长度。

**示例 1:**

```
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
```

**示例 2:**

```
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
```

**示例 3:**

```
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
```

#### Code

```c++
class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int n = s.length();
        if (n <= 1)
        {
            return n;
        }

        int l = 0, r = 1;
        std::unordered_set<char> set;
        set.insert(s[l]);
        int res = 0;
        while (r < n)
        {
            while (r < n && set.find(s[r]) == set.end())
            {
                set.insert(s[r]);
                r++;
            }
            res = std::max(res, r-l);
            set.erase(s[l]);
            l++;
        }
        return res;
    }
};
```

使用了set集合，可以排除重复的项。这个完全不需要左右指针。判断完一个字符后可以通过 l++ 进行到下一个字符。

### T4	寻找两个正序数组的中位数

给定两个大小分别为 `m` 和 `n` 的正序（从小到大）数组 `nums1` 和 `nums2`。请你找出并返回这两个正序数组的 **中位数** 。

算法的时间复杂度应该为 `O(log (m+n))` 。

示例 1：

```
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
```

示例 2：

```
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
```

#### Analysis

首先，创建一个空的vector ans，用于存储合并后的有序数组。
初始化四个指针：n1和n2分别指向nums1和nums2的起始位置，a1和a2分别记录已经合并到ans中的元素个数。
对nums1和nums2进行排序，使它们分别按升序排列。
在一个循环中，比较nums1[n1]和nums2[n2]指向的元素：
如果nums1[n1]大于等于nums2[n2]，则将nums2[n2]加入ans中，同时将n2和a2递增1。
否则，将nums1[n1]加入ans中，同时将n1和a1递增1。
每一次比较操作都会向ans中添加一个元素。
循环结束后，判断是否还有剩余的元素未添加到ans中：
如果a1小于nums1的长度，说明nums1还有剩余元素未添加到ans中，将剩余元素全部添加到ans中。
如果a2小于nums2的长度，说明nums2还有剩余元素未添加到ans中，将剩余元素全部添加到ans中。
计算ans的长度n，并根据n的奇偶性来确定返回值：
如果n是奇数，返回ans[n/2]作为中位数。
如果n是偶数，返回(ans[n/2] + ans[(n+1)/2])/2作为中位数。

#### Code

```c++
未优化的
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size(); // 使用 size() 获取 vector 的长度
        int length2 = nums2.size();
        std::vector<int> merged; // 新建一个 vector 来存放合并后的数组

        int i = 0, j = 0;
        while (i < length1 && j < length2) {
            if (nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]); // 使用 push_back 将元素添加到 vector 中
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        // 将剩余的元素添加到 merged 中
        while (i < length1) {
            merged.push_back(nums1[i]);
            i++;
        }
        while (j < length2) {
            merged.push_back(nums2[j]);
            j++;
        }
        int merged_length = merged.size();
        if (merged_length % 2 == 0) {
            // 如果合并后的数组长度为偶数，取中间两个数的平均值
            return (merged[merged_length / 2 - 1] + merged[merged_length / 2]) / 2.0;
        } else {
            // 如果合并后的数组长度为奇数，直接取中间的数
            return merged[merged_length / 2];
        }
    }
};


优化后的
class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> ans; // 用来存储合并后的有序数组
        int n1 = 0, n2 = 0; // 分别表示遍历 nums1 和 nums2 的指针
 
        // 合并两个有序数组，直到其中一个数组的所有元素都被处理完
        while (n1 < nums1.size() && n2 < nums2.size()) {
            // 比较当前指针位置的元素，将较小的元素添加到 ans 中，并将相应指针向后移动一位
            ans.push_back(nums1[n1] >= nums2[n2] ? nums2[n2++] : nums1[n1++]);
        }
 
        // 将剩余未处理的元素添加到 ans 中
        for (; n1 < nums1.size(); n1++) {
            ans.push_back(nums1[n1]);
        }
 
        for (; n2 < nums2.size(); n2++) {
            ans.push_back(nums2[n2]);
        }
 
        int n = ans.size() - 1;
        int medianIndex = n / 2; // 计算中位数的索引位置
 
        // 如果 ans 的长度为奇数，返回中间的元素；如果长度为偶数，返回中间两个元素的平均值
        return (ans[medianIndex] + ans[n - medianIndex]) / 2.0;
    }
};
```

### T5	最长回文数

### T6	Z字型变换

![image-20240626190601896](C:/Users/hp/AppData/Roaming/Typora/typora-user-images/image-20240626190601896.png)

#### 题解

![image-20240626190622256](C:/Users/hp/AppData/Roaming/Typora/typora-user-images/image-20240626190622256.png)

```c++
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 2)
            return s;
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for (char c : s) {
            rows[i].push_back(c);
            if (i == 0 || i == numRows -1)
                flag = - flag;
            i += flag;
        }
        string res;
        for (const string &row : rows)
            res += row;
        return res;
    }
};
```

### T7	整数翻转

#### 题目

给你一个 32 位的有符号整数 `x` ，返回将 `x` 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 `[−231, 231 − 1]` ，就返回 0。

**假设环境不允许存储 64 位整数（有符号或无符号）。**

#### 思路

利用to_string函数直接将所给的整数x转为字符串，假设为s；
忽略前导的负号，用reverse函数反转s的数字部分；
不考虑溢出的情况的话这里就是答案了，如果要判断是否溢出的话需要进行如下操作：
我们引入C++内置的常量INT_MAX和INT_MIN，并且将其转化为字符串形式，假设为t1和t2；
对于负数（具有前导负号）s，如果s的长度=t2的长度（s.length() == t2.length()）且s字典序>t2字典序（s>t2），那么溢出，否则不溢出；
对于正数s，如果s的长度=t1的长度（s.length() == t1.length()）且s字典序>t1字典序（s>t1），那么溢出，否则不溢出。
最后：溢出直接return 0，不溢出则将s用stoi函数转为整型后return即可。

#### Code

```c++
#include <algorithm>
#include <climits>
#include <string>

class Solution {
public:
    int reverse(int x) {
        const int k1 = INT_MAX, k2 = INT_MIN;
        std::string s;
        std::string s1;

        if (x > 0) {
            s = std::to_string(x);
            std::reverse(s.begin(), s.end());
        } else {
            s1 = std::to_string(std::abs(x));
            std::reverse(s1.begin(), s1.end());
            s = '-' + s1;
        }

        // Check if the reversed string is within the int range
        long long reversed_number = std::stoll(s);
        if (reversed_number > k1 || reversed_number < k2) {
            return 0;
        }

        return static_cast<int>(reversed_number);
    }
};

```

### T8	字符串转整数

#### 题目

请你来实现一个 `myAtoi(string s)` 函数，使其能将字符串转换成一个 32 位有符号整数。

函数 `myAtoi(string s)` 的算法如下：

1. **空格：**读入字符串并丢弃无用的前导空格（`" "`）
2. **符号：**检查下一个字符（假设还未到字符末尾）为 `'-'` 还是 `'+'`。如果两者都不存在，则假定结果为正。
3. **转换：**通过跳过前置零来读取该整数，直到遇到非数字字符或到达字符串的结尾。如果没有读取数字，则结果为0。
4. **舍入：**如果整数数超过 32 位有符号整数范围 `[−231, 231 − 1]` ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 `−231` 的整数应该被舍入为 `−231` ，大于 `231 − 1` 的整数应该被舍入为 `231 − 1` 。

返回整数作为最终结果。

#### 题解

这道题说实话没有什么难度，无非就是处理数字、符号、空格和 int 溢出的细节问题，具体看代码吧，把每一步的注释写清楚就不容易在细节上出错了。

#### Code

```c++
class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        int i = 0;
        // 记录正负号
        int sign = 1;
        // 用 long 避免 int 溢出
        long res = 0;
        // 跳过前导空格
        while (i < n && str[i] == ' ') {
            i++;
        }
        if (i == n) {
            return 0;
        }

        // 记录符号位
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }
        if (i == n) {
            return 0;
        }

        // 统计数字位
        while (i < n && '0' <= str[i] && str[i] <= '9') {
            res = res * 10 + str[i] - '0';
            if (res > INT_MAX) {
                break;
            }
            i++;
        }
        // 如果溢出，强转成 int 就会和真实值不同
        if ((int) res != res) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        return (int) res * sign;
    }
};
```

### T13	罗马数字转数字

#### 题目

罗马数字包含以下七种字符: `I`， `V`， `X`， `L`，`C`，`D` 和 `M`。

```
字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
```

例如， 罗马数字 `2` 写做 `II` ，即为两个并列的 1 。`12` 写做 `XII` ，即为 `X` + `II` 。 `27` 写做 `XXVII`, 即为 `XX` + `V` + `II` 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 `IIII`，而是 `IV`。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 `IX`。这个特殊的规则只适用于以下六种情况：

- `I` 可以放在 `V` (5) 和 `X` (10) 的左边，来表示 4 和 9。
- `X` 可以放在 `L` (50) 和 `C` (100) 的左边，来表示 40 和 90。 
- `C` 可以放在 `D` (500) 和 `M` (1000) 的左边，来表示 400 和 900。

给定一个罗马数字，将其转换成整数。

#### 题解

通常情况下，罗马数字中小的数字在大的数字的右边。若输入的字符串满足该情况，那么可以将每个字符视作一个单独的值，累加每个字符对应的数值即可。

例如 XXVII 可视作 X+X+V+I+I=10+10+5+1+1=27。

若存在小的数字在大的数字的左边的情况，根据规则需要减去小的数字。对于这种情况，我们也可以将每个字符视作一个单独的值，若一个数字右侧的数字比它大，则将该数字的符号取反。

例如 XIV 可视作 X−I+V=10−1+5=14。

#### Code

```c++
class Solution {
public:
    int romanToInt(string s) {
        int result=0;
        map<char,int> arr={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D', 500},
            {'M', 1000}
        };//初始化哈希表
        for(int i=0;i<s.length();i++)
        {
            if(arr[s[i]] < arr[s[i+1]])
                result -= arr[s[i]];
            else
            {
                result += arr[s[i]];
            }
        }
        return result;
    }
};


```

### T21	合并两个有序链表

#### 题目

将两个升序链表合并为一个新的 **升序** 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。

#### 题解

先通过尾指针找出顺序，再补充完剩下的链表，题目比较简单。

#### Code

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head =  new ListNode();
        ListNode *curr = head;
        while(list1 && list2)
        {
            if(list1->val <= list2->val)
            {
                curr->next = list1;
                list1 = list1 -> next;

            }
            else
            {
                curr->next = list2;
                list2 = list2 -> next;
            }
            curr = curr -> next;
        }
        if(list1)
        {
            
            
                curr -> next =list1;
            
        }
        if(list2)
        {
            
            
                curr -> next =list2;
            
        }
        return head->next;
    }
};
```

### T83	删除链表里的重复数据

#### 题目

给定一个已排序的链表的头 `head` ， *删除所有重复的元素，使每个元素只出现一次* 。返回 *已排序的链表* 。

#### 题解

这题也比较简单，找到删除就行了。

#### Code

```c++
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode *curr = head;
    while (curr != nullptr && curr->next != nullptr) 
    {
        if (curr->val == curr->next->val) {
            ListNode *p = curr->next;
            curr->next = p->next;
            delete p;
        } else {
            curr = curr->next;
        }
    }
    return head;
    }
};
```

### T141	环形链表

#### 题目

给你一个链表的头节点 `head` ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 `pos` 来表示链表尾连接到链表中的位置（索引从 0 开始）。**注意：`pos` 不作为参数进行传递** 。仅仅是为了标识链表的实际情况。

*如果链表中存在环* ，则返回 `true` 。 否则，返回 `false` 。

#### 题解

##### 一：快慢指针法

本方法需要读者对「Floyd 判圈算法」（又称龟兔赛跑算法）有所了解。

假想「乌龟」和「兔子」在链表上移动，「兔子」跑得快，「乌龟」跑得慢。当「乌龟」和「兔子」从链表上的同一个节点开始移动时，如果该链表中没有环，那么「兔子」将一直处于「乌龟」的前方；如果该链表中有环，那么「兔子」会先于「乌龟」进入环，并且一直在环内移动。等到「乌龟」进入环时，由于「兔子」的速度快，它一定会在某个时刻与乌龟相遇，即套了「乌龟」若干圈。

我们可以根据上述思路来解决本题。具体地，我们定义两个指针，一快一慢。慢指针每次只移动一步，而快指针每次移动两步。初始时，慢指针在位置 head，而快指针在位置 head.next。这样一来，如果在移动的过程中，快指针反过来追上慢指针，就说明该链表为环形链表。否则快指针将到达链表尾部，该链表不为环形链表。

```c++
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

if (head == nullptr || head->next == nullptr) { return false; }
首先检查特殊情况：如果链表为空或者只有一个节点，直接返回 false，因为不存在环。

ListNode* slow = head; ListNode* fast = head->next;
初始化慢指针 slow 指向链表的头节点 head，快指针 fast 则指向头节点的下一个节点 head->next。
这里快指针比慢指针领先一步，是为了在开始时就确保慢指针和快指针不在同一个起点，以避免在初始位置就相等导致错误判断。

while (slow != fast) {
这是一个 while 循环，循环条件是慢指针 slow 不等于快指针 fast，即两者没有相遇。

if (fast == nullptr || fast->next == nullptr) { return false; }
在每一轮循环开始时，检查快指针 fast 是否为空或者快指针的下一个节点是否为空。如果是，说明快指针已经到达链表尾部，因此不存在环，直接返回 false。

slow = slow->next; fast = fast->next->next;
如果上面的条件都不满足，进行指针移动：

slow 指针每次向后移动一步。
fast 指针每次向后移动两步。这样做的目的是通过不同的步长来追赶，如果链表中存在环，快慢指针最终会相遇。
return true;

如果 while 循环结束，意味着慢指针 slow 和快指针 fast 相遇，说明链表中存在环，返回 true。
这种方法利用了快慢指针的技巧来判断链表中是否存在环，时间复杂度为 O(n)，空间复杂度为 O(1)，是一种非常高效的解决方案。
```



##### 二：哈希表法*(标志法)*

最容易想到的方法是遍历所有节点，每次遍历到一个节点时，判断该节点此前是否被访问过。

具体地，我们可以使用哈希表来存储所有已经访问过的节点。每次我们到达一个节点，如果该节点已经存在于哈希表中，则说明该链表是环形链表，否则就将该节点加入哈希表中。重复这一过程，直到我们遍历完整个链表即可。

```c++
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> seen;
        while (head != nullptr) {
            if (seen.count(head)) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};

unordered_set<ListNode*> seen;
seen 是一个无序集合，用来存储已经访问过的链表节点指针。使用 unordered_set 是为了保证插入和查找节点的平均时间复杂度为 O(1)。

while (head != nullptr) {
这是一个 while 循环，用来遍历链表。循环条件是 head 指针不为空，即还没有到达链表的末尾。

if (seen.count(head)) {
检查当前节点 head 是否已经存在于集合 seen 中。seen.count(head) 的返回值为 1（true），表示 head 已经存在于集合中，即链表中存在环。

return true;
如果发现链表中存在环，立即返回 true，表示有环。

seen.insert(head);
如果当前节点 head 还未在集合中，将其插入 seen 中，标记为已访问过。

head = head->next;
将 head 指针移动到下一个节点，继续循环检查。

return false;
如果循环结束（即 head 为空），说明链表被完整地遍历了一遍且未发现重复节点，因此链表无环，返回 false。
这种方法利用了哈希集合的特性，通过记录已经访问过的节点，来判断是否存在环，时间复杂度为 O(n)，空间复杂度也为 O(n)，其中 n 是链表的节点数。
```

### T160	相交链表

#### 题目

给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 `null` 。

图示两个链表在节点 `c1` 开始相交**：**

#### 题解

##### 一：哈希表法



##### 二：双指针

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *pA = headA;
        ListNode *pB = headB;
        while(pA != pB)
        {
            pA = (pA == nullptr)? headB : pA -> next;
            pB = (pB == nullptr)? headA : pB -> next;
        }
        return pA;
    }
};
```

### T203	移除链表元素

#### 题目

给你一个链表的头节点 `head` 和一个整数 `val` ，请你删除链表中所有满足 `Node.val == val` 的节点，并返回 **新的头节点** 。

#### 题解

题目比较简单

#### Code

```c++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 处理头节点就是需要删除的情况
        while (head != nullptr && head->val == val) {
            ListNode* toDelete = head;
            head = head->next;
            delete toDelete;
        }

        ListNode *tmp = head ;
        ListNode *ptr = nullptr;
        while(tmp)
        {
            if(tmp -> val == val)
            {
                ptr -> next = tmp -> next;
                tmp = tmp -> next;
                continue;
            }
            ptr = tmp;
            tmp = tmp -> next;
            
                
        }        
        return head;
    }
};
```


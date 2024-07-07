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

### T24	两两交换链表的节点

#### 题目

给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

#### Code

```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode*  dummy = new ListNode(-1);  //虚拟头节点
        dummy->next = head;
        for(auto p = dummy; p->next && p->next->next; )
        {
            auto a = p->next, b = a->next;
            p->next = b;
            a->next = b->next;
            b->next = a;
            p = a;
        }
        return dummy->next;
    }
};


```

### T19	删除链表的第N个节点

#### 题解

快慢指针法

#### code

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
        ListNode *dummyHead = new ListNode(0,head);
        ListNode *fast = head;
        ListNode *slow = dummyHead;
        for(int i = 0;i<n;i++)
        {
            fast = fast -> next;
        }
        while(fast)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        ListNode *d = slow -> next;
        slow -> next = slow -> next -> next;
        delete d;
        ListNode *ans = dummyHead -> next;
        delete dummyHead;
        return ans;
    }
};
```

### T61	旋转链表

#### 题目

给你一个链表的头节点 `head` ，旋转链表，将链表每个节点向右移动 `k` 个位置。

```
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
```

#### 闭合为环

记给定链表的长度为 n，注意到当向右移动的次数 k≥n 时，我们仅需要向右移动 kmodn 次即可。因为每 n 次移动都会让链表变为原状。这样我们可以知道，新链表的最后一个节点为原链表的第 (n−1)−(kmodn) 个节点（从 0 开始计数）。

这样，我们可以先将给定的链表连接成环，然后将指定位置断开。

具体代码中，我们首先计算出链表的长度 n，并找到该链表的末尾节点，将其与头节点相连。这样就得到了闭合为环的链表。然后我们找到新链表的最后一个节点（即原链表的第 (n−1)−(kmodn) 个节点），将当前闭合为环的链表断开，即可得到我们所需要的结果。

特别地，当链表长度不大于 1，或者 k 为 n 的倍数时，新链表将与原链表相同，我们无需进行任何处理。

```c++
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }
        
        // 计算链表长度，并将尾节点指向头节点，形成循环链表
        int length = 1;
        ListNode *tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }
        tail->next = head;
        
        // 计算实际需要旋转的次数
        k = k % length;
        
        // 找到新头节点的前一个节点
        ListNode *newTail = head;
        for (int i = 0; i < length - k - 1; ++i) {
            newTail = newTail->next;
        }
        
        // 新的头节点
        ListNode *newHead = newTail->next;
        
        // 断开环
        newTail->next = nullptr;
        
        return newHead;
    }
};

```

### T20	有效的括号

#### 题目

给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s` ，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。
3. 每个右括号都有一个对应的相同类型的左括号。   

#### 题解

判断括号的有效性可以使用「栈」这一数据结构来解决。

我们遍历给定的字符串 s。当我们遇到一个左括号时，我们会期望在后续的遍历中，有一个相同类型的右括号将其闭合。由于后遇到的左括号要先闭合，因此我们可以将这个左括号放入栈顶。

当我们遇到一个右括号时，我们需要将一个相同类型的左括号闭合。此时，我们可以取出栈顶的左括号并判断它们是否是相同类型的括号。如果不是相同的类型，或者栈中并没有左括号，那么字符串 s 无效，返回 False。为了快速判断括号的类型，我们可以使用哈希表存储每一种括号。哈希表的键为右括号，值为相同类型的左括号。

在遍历结束后，如果栈中没有左括号，说明我们将字符串 s 中的所有左括号闭合，返回 True，否则返回 False。

注意到有效字符串的长度一定为偶数，因此如果字符串的长度为奇数，我们可以直接返回 False，省去后续的遍历判断过程。

#### code

```c++
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n % 2 != 0)
        {
            return false;
        }
        unordered_map<char,char> pairs =
        {
            {')','('},
            {'}','{'},
            {']','['}
        };
        stack<char>  stk;
        for(char c:s)
        {
            if(pairs.count(c))
            {
                if(stk.empty() || stk.top()!=pairs[c])
                {
                    return false;
                }
                else
               
                stk.pop();
            }
            else
                stk.push(c);
        }
        return stk.empty();
    }
};
```

### T144 二叉树前序遍历

见pdf

### T1021	删除最外层的括号

#### 题目

**示例 1：**

```
输入：s = "(()())(())"
输出："()()()"
解释：
输入字符串为 "(()())(())"，原语化分解得到 "(()())" + "(())"，
删除每个部分中的最外层括号后得到 "()()" + "()" = "()()()"。
```

#### 题解

1. **字符串处理和堆栈使用**：
	- `s` 是输入的字符串，表示一个由括号字符 `'('` 和 `')'` 组成的字符串。
	- `res` 是用于存储处理后的结果的字符串。
	- `stack<char> st` 是一个堆栈，用来辅助处理括号的嵌套关系。
2. **遍历字符串 `s`**：
	- `for(auto c:s)` 遍历字符串 `s` 中的每个字符 `c`。
3. **处理右括号 `')'`**：
	- `if(c == ')') { st.pop(); }`：当遇到右括号时，表示一个内部嵌套的部分结束，从堆栈 `st` 中弹出对应的左括号 `'('`。
4. **处理非空堆栈情况**：
	- `if(!st.empty()) { res.push_back(c); }`：只有在堆栈不为空的情况下，才将当前字符 `c` 添加到结果字符串 `res` 中。这确保了只添加原语内部的字符，即去除了原语外部的最外层括号。
5. **处理左括号 `'('`**：
	- `if(c == "(") { st.emplace(c); }`：当遇到左括号时，将其推入堆栈 `st` 中，以便记录当前内部嵌套的起始。

#### 可能的问题和改进：

- **效率改进**：每次处理字符时都进行堆栈的操作和判断，可以考虑优化，例如不用堆栈而是计数器来统计嵌套深度，这样可能会更高效。

#### code

```c++
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        stack<char> st;

        for(auto c:s)
        {
            if(c == ')')
            {
                st.pop();
            }
            if(!st.empty())
            {
                res.push_back(c);
            }
            if(c == '(')
            {
                st.emplace(c);
            }
        }
        return res;
    }
};




改进后：
class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int openCount = 0;

        for(auto c : s) {
            if (c == ')') 
            {
                if (openCount > 1) 
                {
                    res.push_back(c);
                }
                openCount--;
            } 
            else if (c == '(') 
            {
                if (openCount > 0) 
                {
                    res.push_back(c);
                }
                openCount++;
            }
        }
        return res;
    }
};

```

### T14	最长开头字符串

#### 题目

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 `""`。

**示例 1：**

```
输入：strs = ["flower","flow","flight"]
输出："fl"
```

#### 题解

1. **参数检查与初始化**：
	- 首先检查 `strs` 是否为空，如果为空则直接返回空字符串 `""`。
	- 获取字符串数组的长度 `len`，并初始化一个空字符串 `cstr`，用于存储当前可能的最长公共前缀。
2. **外层循环 - 字符串遍历**：
	- 使用 `for(auto ch : strs[0])` 循环遍历第一个字符串 `strs[0]` 中的每一个字符 `ch`。
	- 将当前字符 `ch` 加入到 `cstr` 中，以形成一个逐步增长的潜在公共前缀。
3. **内层循环 - 前缀匹配检查**：
	- 对于每个字符 `ch` 添加到 `cstr` 后，再次遍历整个字符串数组 `strs`。
	- 使用 `strs[i].find(cstr)` 来检查当前字符串 `strs[i]` 是否以 `cstr` 开头。
	- 如果 `find` 返回 `0`，表示找到了 `cstr` 开头位置，继续下一个字符串的检查。
	- 如果 `find` 返回 `std::string::npos`（未找到），则说明 `cstr` 不是当前字符串的前缀，此时需要回退 `cstr.pop_back()`，并返回当前的 `cstr`。
4. **返回结果**：
	- 最后，如果所有字符串都能匹配到当前 `cstr`，则 `cstr` 将是最长的公共前缀；如果找不到匹配的前缀，则会返回空字符串 `""`。

#### code

```c++
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    
    {

        if(!strs.size())
            return "";
        int len = strs.size();
        string cstr;
        for(auto ch : strs[0])
        {
            cstr += ch;
            for(int i = 0; i<len;i++)
            {
                if(!strs[i].find(cstr))
                {
                    continue;
                }
                else
                {
                    if(!cstr.empty())
                    {
                        cstr.pop_back();
                        return cstr;
                    }
                }
                    
            }
        }
        return cstr;       
    }
};
```

### T15	三数之和

很经典的题目，哈哈哈，官解实在是看的有点迷糊

#### 题目

给你一个整数数组 `nums` ，判断是否存在三元组 `[nums[i], nums[j], nums[k]]` 满足 `i != j`、`i != k` 且 `j != k` ，同时还满足 `nums[i] + nums[j] + nums[k] == 0` 。请

你返回所有和为 `0` 且不重复的三元组。

**注意：**答案中不可以包含重复的三元组。

**示例 1：**

```
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
```

#### 题解

1. **排序数组**：

	- 首先，对数组 `nums` 进行排序。排序的主要目的是为了方便使用双指针技术，以及避免重复的解。

2. **双指针技术**：

	- 使用双指针 `l` 和 `r` 分别指向当前元素后面的第一个元素和数组的末尾。初始时，左指针 `l` 在当前元素的后一位，右指针 `r` 在数组末尾。

3. **遍历和判断**：

	- 对数组进行遍历，以每一个元素作为当前元素 `nums[i]`。对于当前元素 `nums[i]`，设定 `l = i + 1`，`r = len - 1`。
	- 在内部循环中，计算当前三个指针所指元素的和 `sum = nums[i] + nums[l] + nums[r]`。

4. **调整指针**：

	- 如果

		```
		sum == 0
		```

		，则找到了一个符合条件的三元组

		```
		(nums[i], nums[l], nums[r])
		```

		，将其加入结果集中，并进一步调整指针避免重复解：

		- 移动 `l` 和 `r` 至下一个不同的元素，以避免重复。

	- 如果 `sum > 0`，说明右侧的数值过大，需要减小 `r`。

	- 如果 `sum < 0`，说明左侧的数值过小，需要增大 `l`。

5. **去重处理**：

	- 在外层循环中，如果当前元素 `nums[i]` 与前一个元素相同，则跳过，以避免计算重复的三元组。

6. **结束条件**：

	- 外层循环遍历完所有可能的 `nums[i]`，内部双指针遍历也完成了所有可能的组合。

7. **返回结果**：

	- 最终返回结果集，其中包含所有满足条件的三元组。

### 复杂度分析：

- **时间复杂度**：主要由排序算法决定，通常为 O(n log n)，加上双指针遍历为 O(n^2)。总体为 O(n^2)。
- **空间复杂度**：除了存储结果的空间外，额外的空间复杂度是 O(1)，因为只使用了常数级的额外空间。

这种方法通过排序和双指针技术，有效地减少了问题的复杂度，使得在合理的时间内找到所有解。

#### code

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = len - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    result.push_back({nums[i], nums[l], nums[r]});
                    // Skip duplicates
                    while (l < r && nums[l] == nums[l + 1]) ++l;
                    while (l < r && nums[r] == nums[r - 1]) --r;
                    ++l;
                    --r;
                } else if (sum > 0) {
                    --r;
                } else { // sum < 0
                    ++l;
                }
            }
        }

        return result;
    }
};

```

### T16	最接近的三数之和

和上一题倒是很接近，我们可以参考

#### 题目

略

#### code

```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 排序数组，便于双指针法
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; // 初始最接近的和为前三个数的和

        for (int i = 0; i < len - 2; ++i) {
            int l = i + 1;
            int r = len - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                // 更新最接近的和
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }
                // 根据当前和与目标的大小关系移动指针
                if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
        }

        return closestSum;
    }
};

```


/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        // 翻转字符串便于模拟进位
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());


        //存储结果
        string result;

        int carry = 0; // 进位
        int i = 0; // 迭代器

        int m = a.size(), n = b.size();

        int index = max(m, n);

        while(i < index || carry > 0){// 考虑到进位
            int val = carry;
            val += i < m ? a[i] - '0' : 0;
            val += i < n ? b[i] - '0' : 0;
            result += val % 2 + '0';
            carry = val / 2;
            i++;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end


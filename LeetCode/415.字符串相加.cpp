/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string result;

        int carry = 0; // 进位
        int index = 0; // 迭代器
        int m = num1.size(), n = num2.size();

        int i = max(m, n);

        while(index < i || carry > 0){
            int val = carry;
            val += index < m ? num1[index] - '0' : 0;
            val += index < n ? num2[index] - '0' : 0;
            result += val % 10 + '0';
            carry = val / 10;
            index++;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end


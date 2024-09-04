/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1 , b1 , a2 , b2;
        int r1 , r2;
        char op;
        stringstream ss1(num1);
        stringstream ss2(num2);

        ss1 >> a1 >> op >> b1;
        ss2 >> a2 >> op >> b2;

        r1 = a1 * a2 - b1 * b2;
        r2 = a1 * b2 + a2 * b1;
        return to_string(r1) +"+"+ to_string(r2) + "i";

    }
};
// @lc code=end


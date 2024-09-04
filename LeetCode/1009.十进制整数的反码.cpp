/*
 * @lc app=leetcode.cn id=1009 lang=cpp
 *
 * [1009] 十进制整数的反码
 */

// @lc code=start
class Solution {
public:
    int bitwiseComplement(int n) {
        if (!n) return 1;
        unsigned int mask = ~0;
        while (mask & n) mask <<= 1;
        return mask ^ ~n;
    }
};

// @lc code=end


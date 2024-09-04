/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */

// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        string temp = to_string(n);
        return next_permutation(temp.begin(), temp.end()) && stol(temp) <= INT_MAX ? stol(temp) : -1; 
    }
};
// @lc code=end


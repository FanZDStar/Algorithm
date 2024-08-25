/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        t.erase(t.begin()); 
        t.erase(t.end() - 1); // 掐头去尾
        if (t.find(s) != std::string::npos) 
            return true; // r
        return false;
    }
};

// @lc code=end


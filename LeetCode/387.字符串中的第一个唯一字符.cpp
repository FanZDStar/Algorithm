/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for (char c : s) 
            // 将字符转化成数字
            count[c - 'a']++;
        
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (count[c - 'a'] == 1) 
                // 第一个出现一次的字符
                return i;
            
        }
        return -1;
    }
};
// @lc code=end


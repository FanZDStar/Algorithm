/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        char last = '-';
        int cnt_pre = 0;
        int cnt_cur = 0;

        s += '-';
        for (auto c : s) {
            if (last != c) {
                last = c;
                ans += min(cnt_pre, cnt_cur);
                cnt_pre = cnt_cur;
                cnt_cur = 0;
            }
            cnt_cur++;
        }
        return ans;
    }
};

// @lc code=end


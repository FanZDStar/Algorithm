/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto &c : moves){
            x += (c == 'R');
            y += (c == 'U');
            x -= (c == 'L');
            y -= (c == 'D');
        }
        return x == 0 && y == 0;
    }
};
// @lc code=end


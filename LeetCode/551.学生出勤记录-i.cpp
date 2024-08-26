/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        for(int i = 0; i<s.size();i++){
            a += (s[i] == 'A');
            l = (s[i] == 'L')?l + 1 : 0;
            if(a >= 2 || l >= 3)
                return false;
            
        }
        return true;
    }
};
// @lc code=end


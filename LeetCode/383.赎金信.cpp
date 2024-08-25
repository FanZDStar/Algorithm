/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size())
            return false;
        vector <int> vec(26);
        for(auto & c : magazine)
            vec[c - 'a']++;
        for(auto & c : ransomNote){
            vec[c - 'a']--;
            if(vec[c - 'a'] < 0)
                return false;
        }
        return true;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int start = 0 , end = s.size() - 1;
        while(start <= end){
            if(s[start] != s[end])
                return isOk(s,start+1,end) || isOk(s,start,end-1);
            start++;
            end--;
            
        }
        return true;
    }
private:
    bool isOk (string s, int start, int end){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }

        return true;
    }
};
// @lc code=end


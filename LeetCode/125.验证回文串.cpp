/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        int length = s.length();
        for(int i = 0; i < length; i++){
            if(isalnum(s[i]))  str += tolower(s[i]);
            
            
        }
        int left = 0, right = str.length() - 1;
        while(left < right){
            if(str[left] != str[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
// @lc code=end


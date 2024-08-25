/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int i = 0; // 左指针
        int j = s.size() - 1;// 右指针

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        while(i < j){
            while(!vowels.count(s[i]) && i < s.size())
                i++;
            while(!vowels.count(s[j]) && j > 0)
                j--;


            if(i >= j)
                break;
            swap(s[i++],s[j--]);
        }
        return s;
    }
};
// @lc code=end


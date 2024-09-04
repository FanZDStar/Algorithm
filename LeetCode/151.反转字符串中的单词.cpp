/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:

    
    string reverseWords(string s) {
        vector<string> words;
        stringstream ss(s);
        string word;
        while(ss >> word)
            words.push_back(word);

        int l = words.size();
        string str = words[l - 1];
        for(int i = l - 2; i >= 0; i--){
            str += (" " + words[i]);
        }   

        return str;
    }

};
// @lc code=end


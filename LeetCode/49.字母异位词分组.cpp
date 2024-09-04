/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string,vector<string>> um;
        for(string &str : strs){
            string s = str;
            sort(s.begin(),s.end());
            um[s].push_back(str);
        }
        vector<vector<string>> results;
        for(const pair <string,vector<string>>&n : um)results.push_back(n.second);
        return results;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());

        for(auto intr : intervals){
            if(res.empty() || res.back()[1] < intr[0])
                res.push_back(intr);
            else
                res.back()[1] = max(res.back()[1],intr[1]); 
        }
        return res;
    }
};
// @lc code=end


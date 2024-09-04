/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin() , intervals.end());
        vector<vector<int>> res;

        for(auto i : intervals){
            if(res.empty() || res.back()[1] < i[0])
                res.push_back(i);
            else
                res.back()[1] = max(res.back()[1],i[1]);
        }
        return res;
    }
};
// @lc code=end


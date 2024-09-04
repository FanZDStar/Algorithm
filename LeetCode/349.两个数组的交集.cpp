/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        for(auto &n : nums1){
            auto it = find(nums2.begin(),nums2.end(),n);
            if(it != nums2.end())
                s.emplace(n);
        }
        vector<int> results;
        for(int n : s){
            results.push_back(n);
        }
        return results;
    }
};
// @lc code=end


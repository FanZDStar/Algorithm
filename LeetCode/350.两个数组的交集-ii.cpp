/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            intersect(nums2,nums1);
        unordered_map<int,int>results;

        for(int m : nums1)
            ++results[m];
        vector<int> vec;
        for(int num : nums2)
        {
            if(results.count(num)){
                vec.push_back(num);
                --results[num];
                if(results[num] == 0){
                    results.erase(num);
                }
            }
        }
        return vec;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include<vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return left_bound(nums,target);
    }


    // 二分法
    int left_bound(vector<int>nums,int target){
        if(nums.size() == 0) return -1;

        int left = 0, right = nums.size();

        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                right = mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

};
// @lc code=end


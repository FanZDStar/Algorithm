/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int Nmax = nums[0], Nmin = nums[0];
        for(auto c : nums){
            Nmax = max(Nmax,c);
            Nmin = min(Nmin,c);
        }

        return (Nmax - Nmin) <= 2 * k ? 0 : Nmax - Nmin - 2 * k;
    }
};
// @lc code=end


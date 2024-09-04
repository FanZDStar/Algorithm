/*
 * @lc app=leetcode.cn id=883 lang=cpp
 *
 * [883] 三维形体投影面积
 */

// @lc code=start
class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int xyArea = 0, yzArea = 0, zxArea = 0;
        for(int i = 0; i < n; ++i){
            int yzHeight = 0, xzHeight = 0;
            for(int j = 0; j < grid.size(); ++j){
                xyArea += (grid[i][j] > 0)? 1:0;
                yzHeight = max(yzHeight,grid[j][i]);
                xzHeight = max(xzHeight,grid[i][j]);

            }

            yzArea += yzHeight;
            zxArea += xzHeight;
        }
        return xyArea+yzArea+zxArea;
    }
};
// @lc code=end


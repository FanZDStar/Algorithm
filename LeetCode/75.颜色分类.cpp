/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1;
        quickSort(nums, left, right);
    }
    int partition(vector<int> &nums, int left, int right)
    { // 选择第一个元素作为枢轴
        int i = left;
        int j = right;
        while (i < j)
        {
            while (i < j && nums[j] >= nums[left])
            {
                --j;
            }
            while (i < j && nums[i] <= nums[left])
            {
                ++i;
            }
            if (i < j)
            {
                swap(nums, i, j);
            }
        }
        swap(nums, left, i);
        return i;
    }
    void quickSort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;
        int pivot = partition(nums, left, right);
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }
    /* 元素交换 */
    void swap(vector<int> &nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
// @lc code=end

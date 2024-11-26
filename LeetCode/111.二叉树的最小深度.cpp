/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        // 如果左子树为空，递归右子树
        if (!root->left)
            return minDepth(root->right) + 1;

        // 如果右子树为空，递归左子树
        if (!root->right)
            return minDepth(root->left) + 1;

        // 左右子树都存在，取左右子树的最小深度
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// @lc code=end
